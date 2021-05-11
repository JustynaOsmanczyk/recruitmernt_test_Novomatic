Content of the task: 
"Write a support mapping function sA(v) for 3D convex shapes that returns point furthest in the direction of vector v."

My comment about the task:
The first question to ask ourselves in order to solve this problem is "What I really need". 
According to my interpretation (mean as I understand the task) of the problem, we want to determine the endpoint of a longest segment contained in the shape in the direction of the given vector. 
We treat a vector as a given from certain directions. 
The end result should be a point on the edge of the solid that is the end of vector V.
For a sphere, capsule, and cuboid, the situation is simple because the requested segment will always contain the center of the solid.
It is possible due to the symmetry of these solids. 
In the case of the tetrahedron, we do not know the point at which to attach the vector.
I analyzed various possibilites for the anchor point: the vertices of the tetrahedron, the center of the sphere inscribed in the tetrahedron and the center of gravity. 
Unfortunately, for each of these points there are many counter-examples, which prevent these points from being an anchor point of the support vector. 
Functions available requirements for points in other solids are based on the calculation of the length between them, as well as the endpoints of the reference points and multiplication of the term versor by it. 
Thus, we get a vector according to the direction and the sense of the vector V, the beginning is the center of the solid and the end point we are looking for.
The longest segment in the sphere is always its diameter. Thus, the support point of the sphere in the direction of a vector v is always in a single radius distance from the center in the vector's direction.
This is a little bit harder to proof but the longest segment in cuboid must contain its center. 
In order to compute the support point, we first find the intersection of the line contating the cuboid center with all its six sides. 
Three of them will be intersections in the direction of v and the remaining three - in the direction of -v. 
Among those first three, we select the closest intersection point. 
It's the actual support of the cuboid.
Similarily, for the capsule we start in the center of the solid. 
In my interpretation, the two points in the Capsule struct represents furthest points of the capsule (ie. the semisphere poles). 
We first compute the angle between the support direction vector and the capsule orientation vector using cosine formula. 
We then compute the distance between the center and the base of the semisphere. We compare the intersection distance from the semisphere center using tangent formula. 
This way, we know whether the support point is on the semisphere or on the cylinder. In the first case, we use the law of cosines to compute the distance from center to the support point. 
In the second case, the distance to the support point is equal to the length of hypotenuse of a right triangle with given angle and a side equal to the cylinder radius.