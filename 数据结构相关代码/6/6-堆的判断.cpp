//在孩子处进行判断 
void Isheap(int a[],int n) 
{
	bool isMaxH=true,isMinH=true;
	for(int i=2;i<=n;i++){
    	if(a[i/2]<a[i]) isMaxH=false;
    	if(a[i/2]>a[i]) isMinH=false;
       }
    
	if(isMinH) cout<<"Min Heap"<<endl;
	else if(isMaxH) cout<<"Max Heap"<<endl;
 	else  cout<<"Not Heap"<<endl;
}

////////////////////////////
//在双亲处进行判断 
void Isheap(int a[],int n) 
{
	bool isMaxH=true,isMinH=true;
	for(int i=1;i<=n/2;i++){
		if(2*i+1>n)
		{
			if(a[i]<a[2*i]) isMaxH=false;
    		if(a[i]>a[2*i]) isMinH=false;
		} 
		else
		{		   	
    		if(a[i]<a[2*i] || a[i]<a[2*i+1] ) isMaxH=false;
    		if(a[i]>a[2*i] || a[i]>a[2*i+1] ) isMinH=false;
    	}
    }
    
	if(isMinH) cout<<"Min Heap"<<endl;
	else if(isMaxH) cout<<"Max Heap"<<endl;
 	else  cout<<"Not Heap"<<endl;
}
