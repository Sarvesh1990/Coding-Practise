#include <iostream>
using namespace std;

//ChecelementToBeRotated if low == high
//If not, checelementToBeRotated if left increasing, if yes, check for element, if found pass left
//If not found checelementToBeRotated for mid
//Pass right
//If left not increasing, checelementToBeRotated for element in right, check for middle, pass left

bool FindElement(int * rotatedArray, int low, int high, int elementToBeRotated)
{
   if(low == high){
       if(rotatedArray[low]==elementToBeRotated)
           return true;
       else
           return false;
    }
   int mid = (low+high)/2;
   if(rotatedArray[low]<=rotatedArray[mid]){
       if(elementToBeRotated>=rotatedArray[low] && elementToBeRotated<=rotatedArray[mid]){
           return FindElement(rotatedArray, low, mid, elementToBeRotated);
        }
       else if (rotatedArray[mid]==elementToBeRotated)
           return true;
       else
           return FindElement(rotatedArray, mid+1, high, elementToBeRotated);
    }
   else{
       if(elementToBeRotated>=rotatedArray[mid] && elementToBeRotated <= rotatedArray[high]){
           return FindElement(rotatedArray, mid, high, elementToBeRotated);
        }
       else if(rotatedArray[mid]==elementToBeRotated)
           return true;
       else
           return FindElement(rotatedArray, low, mid-1,elementToBeRotated);
    }
}

int main()
{
	cout<<"Give number of elements to be inserted in array"<<endl;
	int length;
	cin>>length;
	int rotatedArray[length];
	for(int i=0; i<length; i++)
		cin>>rotatedArray[i];
	cout<<"Give element to be found"<<endl;
	int elementToBeRotated;
	cin>>elementToBeRotated;
    bool found=FindElement(rotatedArray, 0, length-1, elementToBeRotated);
    if(found)
        cout<<"Element "<<elementToBeRotated<<" was found in given  rotated array"<<endl;
    else
        cout<<"Element "<<elementToBeRotated<<" was not found in given  rotated array"<<endl;
}

