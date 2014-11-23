#include "feature.h"
#include <assert.h>

#include "math.h"

using namespace bio;

int Feature::descriptor_length = DEFAULT_DESCR_LEN;

void Feature::copyFeature(Feature& feature, Feature& newFeature){
    newFeature = feature;
}

void Feature::dump(std::ostream & Out) {
    Out << "[Location]: " << "<" << originLoc.x << "," << originLoc.y << ">\n";

    Out << "[Descriptor Leagth] = " << descriptor_length << "\n";
    
    int idx;
    for(idx = 0; idx < descriptor_length; idx ++) {
        Out << descriptor[idx] << " ";
    }
    Out << "\n";
}

int Feature::size() const {
    return Feature::descriptor_length;
}

double & Feature::operator [](int idx) {
    assert(idx < size());

    return descriptor[idx];
}

const double & Feature::operator [] (int idx) const {
    assert(idx < size());

    return descriptor[idx];
}

double Feature::operator - (const Feature & b)  {
    double res = 0;

    int idx;

    for(idx = 0; idx < Feature::descriptor_length; idx++) {
        res += pow((*this)[idx] - b[idx], 2.0);
    }
    return sqrt(res);
}
