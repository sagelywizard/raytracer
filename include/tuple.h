#ifndef TUPLE_H_
#define TUPLE_H_

class Tuple {
  public:
    Tuple(float x, float y, float z, float w) : x_(x), y_(y), z_(z), w_(w) { }

    Tuple operator+(const Tuple& otherTuple) {
        Tuple tuple(x_+otherTuple.x_, y_+otherTuple.y_, z_+otherTuple.z_, w_+otherTuple.w_);
        return tuple;
    }

    Tuple operator-(const Tuple& otherTuple) {
        Tuple tuple(x_-otherTuple.x_, y_-otherTuple.y_, z_-otherTuple.z_, w_-otherTuple.w_);
        return tuple;
    }

    Tuple operator-() {
        Tuple tuple(-x_, -y_, -z_, -w_);
        return tuple;
    }

    Tuple operator*(float multiple) {
        Tuple tuple(multiple*x_, multiple*y_, multiple*z_, multiple*w_);
        return tuple;
    }

    float x_;
    float y_;
    float z_;
    float w_;
};

Tuple operator*(float multiple, const Tuple& tuple) {
    Tuple newTuple(multiple*tuple.x_, multiple*tuple.y_, multiple*tuple.z_, multiple*tuple.w_);
    return newTuple;
}


#endif
