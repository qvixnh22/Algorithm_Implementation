ll ccw(pt a, pt b, pt c){
    return (c.y - a.y) * (b.x - a.x) - (c.x - a.x) * (b.y - a.y);
}
