#include "Bomb_Laser.hpp"

Bomb_Laser::Bomb_Laser() {
	power = 1;
	bombHitNum = 50;
	bombSustainTime = 2.5;
	hitAreas.push_back(RectF(0, 0, 2000, 540));//0:中央の太いレーザー
	hitAreas.push_back(RectF(0, 0, 2000, 80));//1:上の細いレーザー
	hitAreas.push_back(RectF(0, 0, 2000, 80));//2:下の細いレーザー
}

Bomb_Laser::~Bomb_Laser() {

}

Line baseLine;

void Bomb_Laser::setArea() {
	Vec2 launchPos = basePos + Vec2(160, 0);
	hitAreas[0].setPos(launchPos - Vec2(0,270));
	hitAreas[1].setPos(launchPos - Vec2(0, 0));
	hitAreas[2].setPos(launchPos - Vec2(0, 80));
	deg_up = (15 + 5 * sin(bombTime * Math::Pi * 0.8)) * 1_deg;
	deg_down = (-15 - 5 * sin(bombTime * Math::Pi * 0.8)) * 1_deg;
	size_minus = bombTime > 0.5 ? 0 : (0.5 - bombTime) * 400;
	baseLine.set(hitAreas[0].stretched(0, -size_minus).left());
	if (!bombActive) effect_count = 0;
}

bool Bomb_Laser::intercects(Rect rect) {
	if (!hit) return false;
	if (hitAreas[0].stretched(0, -size_minus).intersects(rect)) return true;
	if (hitAreas[1].rotatedAt(basePos + Vec2(100, 0), deg_up).intersects(rect)) return true;
	if (hitAreas[2].rotatedAt(basePos + Vec2(100, 0), deg_down).intersects(rect)) return true;
	return false;
}

bool Bomb_Laser::intercects(Circle circle) {
	if (!hit) return false;
	if (hitAreas[0].stretched(0, -size_minus).intersects(circle)) return true;
	if (hitAreas[1].rotatedAt(basePos + Vec2(100, 0), deg_up).intersects(circle)) return true;
	if (hitAreas[2].rotatedAt(basePos + Vec2(100, 0), deg_down).intersects(circle)) return true;
	return false;
}

struct LineEffect : IEffect {
	Vec2 m_pos;
	double y_per;

	explicit LineEffect(const Vec2& pos)
		: m_pos{ pos } {
		y_per = Random(-0.5, 0.5);
	}

	bool update(double t) override
	{
		// イージング
		const double e = EaseOutSine(t);

		double add_x = 2000 * e;

		double y_pos = baseLine.length() * y_per;

		double x_begin = baseLine.begin.x;
		double y_cent = baseLine.center().y;

		Line{ Vec2(x_begin +add_x, y_cent+y_pos), Vec2(x_begin + add_x + 150, y_cent+y_pos) }.draw(5, Palette::Darkblue.withAlpha(128*(1-e)));

		return (t < 1.0);
	}
};

struct GatherEffect : IEffect {
	Vec2 m_pos;
	Vec2 m_direction;

	explicit GatherEffect(const Vec2& pos, const Vec2& direction)
		: m_pos{ pos },
		  m_direction{direction}  {}

	bool update(double t) override
	{
		t *= 3;
		// イージング
		const double e = EaseInQuad(t);
		Vec2 nowPos = m_pos + m_direction * e;
		Circle(nowPos, 5).draw(Palette::White.withAlpha(196));
		Circle(nowPos, 10).draw(Palette::White.withAlpha(64));

		return (t < 1.0);
	}
};

void Bomb_Laser::addEffect() {
	if (bombSustainTime*0.85 * ((double)effect_count / (double)effect_num) < bombTime && effect_count<effect_num) {
		effect_count++;
		effect.add<LineEffect>(RandomVec2(hitAreas[0].stretched(-10-size_minus, -1990, -10-size_minus, 40)));
		Vec2 v = RandomVec2(500);
		effect.add<GatherEffect>(basePos + Vec2(160, 0) - v, v);
	}
}

void Bomb_Laser::Draw()const {
	if (bombActive) {
		const ScopedRenderStates2D blend{ BlendState::Additive };
		Color laserColor(255, 192, 192, bombSustainTime * 0.9 > bombTime ? 220 : 220 * (bombSustainTime - bombTime)/(0.1*bombSustainTime));
		hitAreas[0].stretched(0, -size_minus).draw(laserColor);
		hitAreas[1].rotatedAt(basePos + Vec2(100, 0), deg_up).draw(laserColor);
		hitAreas[2].rotatedAt(basePos + Vec2(100, 0), deg_down).draw(laserColor);

		Ellipse(basePos + Vec2(160, 0), 80, 270 - size_minus).draw(laserColor);
		Ellipse(basePos + Vec2(160, 0), 50, 240 - size_minus).draw(laserColor);
		Ellipse(basePos + Vec2(160, 0), 30, 200 - size_minus).draw(laserColor);
	}
	
	effect.update();
}
