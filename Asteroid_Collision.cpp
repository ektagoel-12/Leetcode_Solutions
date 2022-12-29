//    https://leetcode.com/problems/asteroid-collision/description/


// Intuition
// Use stack for accessing the latest element to see if their is a collision.

// Always see the direction of elements( Like first element moving left and second element moving right will never collide ).

// Approach
// Create an empty stack and a boolean variable "collide" to check the status of putting new asteroid in the stack or not.
// Iterate over the array.
// At each itration , we will check if the stack is empty or not .
// If the stack is empty then push the element in the stack.
// If the stack is not empty, then we'll check the top element of the stack .
// if the topmost element of stack is positive and new enetered asteroid is negative thencheck the magnitude of each.
// if the magnitude of stack element is smaller than new asteroid the pop the element from stack and check further by applying continue.
// If it's oppsite then nothing happens and the asteroid will not enter the stack by making collide variable false.
// If the magnitude of both of them is same them the element is popped out from the stack and the new asteroid will also not enter by making collide false.
// After the coompletion of iterations , push all the elements of the stack in a vector and then reverse it because it follows the LIFO order.


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        vector<int>v;
        bool collide=true;
        for(int i=0;i<asteroids.size();i++)
        {
            collide=true;
            while( !s.empty() && (s.top()>0 && asteroids[i]<0 ) )
            {
                if( abs(asteroids[i]) > s.top() ){
                    s.pop();
                    collide=true;
                    continue;
                }
                else if( abs(asteroids[i])<s.top()){
                    collide=false;
                    break;
                }
                else{
                    s.pop();
                    collide=false;
                    break;
                }
            }
            if(collide){
                s.push(asteroids[i]);
            }
        }
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};



