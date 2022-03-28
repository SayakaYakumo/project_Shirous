#pragma once

struct CircleEffect : IEffect
{
	Vec2 m_pos;

	ColorF m_color;

	double m_firstSize;

	bool m_isShrink;

	explicit CircleEffect(const Vec2& pos, double size = 200, bool isShrink = true)
		: m_pos{ pos }
		, m_firstSize(size)
		, m_isShrink(isShrink)
		, m_color{ Palette::Antiquewhite.withAlpha(196) } {}

	bool update(double t) override
	{
		t *= 2;

		if (t > 1) t = 1;

		Circle{ m_pos, m_firstSize * ( m_isShrink ? (1-t) : t) }.drawFrame(4, m_color);

		return (t < 1.0);
	}
};

struct SmokeEffect : IEffect
{
	ColorF m_color;

	//Array<Circle> m_circles;
	double sizes[10];
	Vec2 poses[10];

	double move_x = 200;
	double move_y = 300;
	Vec2 m_pos;

	explicit SmokeEffect(const Vec2& pos)
		: m_pos(pos)
		, m_color{ Palette::Antiquewhite.withAlpha(196) }
	{
		for (int i = 0; i < 10; i++) {
			sizes[i] = Random(5.0, 30.0);
			poses[i] = RandomVec2(Circle(30));
		}
	}

	bool update(double t) override
	{
		t *= 1;
		if (t > 1) t = 1;

		double e_x = EaseOutQuint(t);
		double e_y = EaseInSine(t);

		for (int i = 0; i < 10; i++) {
			double x = e_x * move_x * (35.0 - sizes[i]) / 30.0;
			double y = e_y * move_y * (35.0 - sizes[i]) / 30.0;
			Circle(m_pos + poses[i] + Vec2(i < 5 ? 80 + x : -80 - x, -y), sizes[i])
				.draw(Palette::Ghostwhite.withAlpha(128 * (1 - t))).drawFrame(5, Palette::Ghostwhite.withAlpha(196*(1-t)));
		}

		return (t < 1.0);
	}
};

struct DamageEffect : IEffect
{
	Vec2 m_pos;

	ColorF m_color;

	Vec2 move_vecs[10];
	double length[10];

	explicit DamageEffect(const Vec2& pos)
		: m_pos{ pos }
		, m_color{ Palette::Antiquewhite.withAlpha(196) }
	{
		for (int i = 0; i < 10; i++) {
			move_vecs[i] = RandomVec2(Circle(300));
			length[i] = Random(20.0, 150.0);
		}
	}

	bool update(double t) override
	{
		t *= 2;

		if (t > 1) t = 1;

		double e = EaseOutQuart(t);

		//Circle{ m_pos, m_firstSize * (m_isShrink ? (1 - t) : t) }.drawFrame(4, m_color);

		for (int i = 0; i < 10; i++) {
			//Circle(m_pos + move_vecs[i] * e, 20).draw(Palette::Orangered.withAlpha(128*(1-t)));
			Line(m_pos + move_vecs[i] * e, m_pos + move_vecs[i] * e + move_vecs[i].normalized()*length[i])
				.draw(5, Palette::Orangered.withAlpha(128 * (1 - t)));
		}

		return (t < 1.0);
	}
};
