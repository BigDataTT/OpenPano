// File: matcher.hh
// Date: Wed May 01 23:05:10 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once
#include <vector>
#include <utility>
#include "feature.hh"

class MatchData {
	public:
		std::vector<Coor> data;
		MatchData(){}

		MatchData(const MatchData& r):
			data(r.data) {}

		MatchData(MatchData&& r):
			data(move(r.data)) {}

		void add(const Coor&);

		int size() const { return data.size(); }
};

class Matcher {
	protected:
		const std::vector<Feature> &feat1, &feat2;

		real_t cal_dist(const Feature& x, const Feature& y) const;
	public:
		Matcher(const std::vector<Feature>& f1, const std::vector<Feature>& f2):
			feat1(f1), feat2(f2) { }

		MatchData match() const;


};
