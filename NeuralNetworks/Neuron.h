#pragma once

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <random>

class Neuron
{
public:
	Neuron(uint32_t aNumWeights);
	~Neuron();
	float feedForward(const std::vector<float> &aInputs) const;

	friend std::ostream& operator<<(std::ostream& os, const Neuron &aNeuron);

private:
	std::vector<float> mWeights;
	float mBias;
};


