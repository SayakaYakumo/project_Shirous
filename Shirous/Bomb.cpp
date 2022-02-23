#include "Bomb.hpp"

Bomb::Bomb() {

}

Bomb::~Bomb() {

}

void Bomb::Start() {
	if (bombNum <= 0) return;
	bombNum--;
	bombTime = 0;
	bombActive = true;
	hitCount = 0;
}

void Bomb::Update(double deltaTime, Vec2 playerPos) {
	hit = false;
	basePos = playerPos;
	setArea();
	if (!bombActive) return;

	if ((bombSustainTime * (double)hitCount / (double)bombHitNum) < bombTime) {
		hit = true;
		hitCount++;
		if (hitCount == bombHitNum) bombActive = false;
	}

	addEffect();

	bombTime += deltaTime;
}

void Bomb::setArea() {
	//ここでは使わないが、継承した際には使う
}

bool Bomb::intercects(Rect rect) {
	return hit;
}

bool Bomb::intercects(Circle circle) {
	return hit;
}

bool Bomb::isActive() const {
	return bombActive;
}

int Bomb::getBombNum() const {
	return bombNum;
}

struct BubbleEffect : IEffect
{
	struct Bubble
	{
		Vec2 offset;
		double startTime;
		double scale;
		ColorF color;
	};

	Vec2 m_pos;

	Array<Bubble> m_bubbles;

	BubbleEffect(const Vec2& pos)
		: m_pos{ pos }
	{
		for (int32 i = 0; i < 8; ++i)
		{
			Bubble bubble{
				.offset = RandomVec2(Circle{30}),
				.startTime = Random(-0.3, 0.1), // 登場の時間差
				.scale = Random(0.1, 1.2),
				.color = HSV{ 30 + Random(-30.0, 30.0) }
			};
			m_bubbles << bubble;
		}
	}

	bool update(double t) override
	{
		for (const auto& bubble : m_bubbles)
		{
			const double t2 = (bubble.startTime + t);

			if (not InRange(t2, 0.0, 1.0))
			{
				continue;
			}

			const double e = EaseOutExpo(t2);

			Circle{ (m_pos + bubble.offset + (bubble.offset * 4 * t)), (e * 80 * bubble.scale) }
				.draw(ColorF{ bubble.color, 0.80*(1.0-t) })
				.drawFrame((50.0 * (1.0 - e) * bubble.scale), bubble.color.withAlpha(1.0-t));
		}

		return (t < 1.3);
	}
};

void Bomb::addEffect() {
	if (hit) {
		for (int i = 0; i < 5; i++)
			effect.add<BubbleEffect>(RandomVec2(Scene::Rect().stretched(-100)));
	}
}

void Bomb::Draw()const {
	//if (bombActive)Scene::Rect().draw(Color(255, 0, 0, 128));
	effect.update();
}

