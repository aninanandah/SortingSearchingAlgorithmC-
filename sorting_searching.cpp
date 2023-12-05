#include <iostream>


class bubble
{
       public:
       int* process(int *arr, int ukuran)
       {

	while(ukuran>0)
             {
   	     for(int i=1;i<ukuran;i++)
                 {
      	        if(arr[i-1]>arr[i])
                    {
         	              int temp=arr[i-1];
              arr[i-1]=arr[i];
           	              arr[i]=temp;
 }
             }
      	  ukuran--;
         }
       return arr;
     }
};

class insertion
{
public:
  int* process(int *arr, int ukuran)
  {
   int max,j;
   int i=1;

     while(i<ukuran)
     {
   	max=arr[i];
           for(j=i;j>0;j--)
           {
      	if(max<arr[j-1])
               	arr[j]=arr[j-1];
             else
         	  break;
            }
         arr[j]=max;
         i++;
   }
     return arr;
  }
};


class radix
    {
 public:
 int cekbit(int arr, int pos)
 {
    for(int i=1;i<pos;i++)
    {
  		arr=arr/2;
    }

    return arr%2;
 }

 int* process(int *arr, int ukuran)
 {
	int bit;
	cout<<"masukkan jumlah bit yang diinginkan ";
       cin>>bit;
  	int s;
       int *kembar;
       kembar=new int[ukuran];
       for(int i=1;i<bit;i++)
       {
   	     s=0;
           for(int k=0;k<=1;k++)
           {
      	         for(int j=0;j<ukuran;j++)
               {
         	int x=cekbit(arr[j],i);
                    if(x==k)
                    {
            	    kembar[s]=arr[j];
                        s++;
                    }
               }
            }
               tukar(arr,kembar,ukuran);
               }
          return arr;
       }

       int* tukar(int *arr,int *kembar,int ukuran)
      {
         for(int i=0;i<ukuran;i++)
        {
   	arr[i]=kembar[i];
     }
 	return arr;
   }
};

class counting
{
   public:
   int* process(int *arr,int ukuran)
      {
      	int i,j,k,min,max;
             int indeks=0;

         min=max=arr[0];
        for(i=1;i<ukuran;i++)
        {
          if(arr[i]<min)
          {
         	min=arr[i];
          }

         if(arr[i]>max)
          {
            max=arr[i];
          }
        }

         k=max-min+1;
         /// membuat bucket
               int *B=new int[k];

         ///normalisasi nilai bucket
         for(i=0;i<k;i++)
         	B[i]=0;

         for(i=0;i<ukuran;i++)
             B[arr[i]-min]++;

         for(i=min;i<=max;i++)
         {
         	for(j=0;j<B[i-min];j++)
            	arr[indeks++]=i;
         }
         return arr;
      }
};

class sequencsearch
{
   int found;
   public:
      int sequence(int *arr,int find,int ukuran)
      {
         int hasil=0;
         for(int i=0;i<ukuran;i++)
         {
         	if(find==arr[i])
            {
               hasil=1;
               found=i;
               break;
            }
         }

         return hasil;
      }

      int getfound()
      {
      	return found;
      }
};

class binarysearch
{
     int found;
     public:
     int binary(int *arr,int find,int ukuran)
     {
     	  int high=ukuran-1;
         int low=0;
         int hasil=0;
         while(low<=high)
         {
             int mid=(high+low)/2;

            if(find==arr[mid])
            {
                found=mid;
                hasil=1;
                break;
            }else if(find>arr[mid])
            	low=mid+1;
            else
            	high=mid-1;
         }
         return hasil;
     }

   int getfound()
   {
   	return found;
   }
};



class utama
{
   public:
     void insert();
     void baca();
     void pengurutan();
     void pencarian(int cari);

   utama(int n)
   {
   	ukuran=n;
   	arr=new int[ukuran];
   }

   private:
      int *arr;
      int ukuran;
      bubble a;
      insertion b;
      radix c;
      counting d;
      sequencsearch e;
      binarysearch f;

};

void utama::insert()
{
  for(int i=0;i<ukuran;i++)
   {
   	cout<<"Nilai ke "<<(i+1)<<":";
      cin>>arr[i];
   }
}

void utama::baca()
{
	cout<<"baca isi array :"<<endl;
   for(int i=0;i<ukuran;i++)
   {
   	cout<<"Isi Array ke "<<(i+1)<<": "<<arr[i]<<endl;
   }
   cout<<endl;
}

void utama::pengurutan()
{
   char n;
   cout<<"Silahkan Pilih Teknik Pengurutan yang diinginkan"<<endl;
   cout<<"1. Bubble sort"<<endl;
   cout<<"2. Insertion sort"<<endl;
   cout<<"3. radix sort"<<endl;
   cout<<"4. counting sort"<<endl;
   cout<<"Masukkan teknik pengurutan yang diinginkan :";
   cin>>n;

   switch(n)
   {
      case '1':
          arr=a.process(arr,ukuran);
          break;
      case '2':
          arr=b.process(arr,ukuran);
          break;
      case '3':
         arr=c.process(arr,ukuran);
         break;
      case '4':
         arr=d.process(arr,ukuran);
         break;
      default:
         cout<<"Pilihan anda salah"<<endl;
   }

}

void utama::pencarian(int cari)
{
    int n,hasil,found;
    cout<<"Masukkan algoritma pencarian yang anda inginkan :"<<endl;
    cout<<"1.Sequencial Search"<<endl;
    cout<<"2.Binary Search"<<endl;
    cout<<"Pencarian :";
    cin>>n;

    if(n==1)
    {
    	  hasil=e.sequence(arr,cari,ukuran);
	  found=e.getfound();
    }else if(n==2)
    {
      	  hasil=f.binary(arr,cari,ukuran);
         found=f.getfound();
    }else
    {
    	 cout<<"angka yang anda masukkan salah "<<endl;
    }

    if(hasil==1)
    {
    	cout<<"nilai "<<cari<<" ditemukan pada index ke "<<(found+1)<<endl;
    }else
    {
    	cout<<"Angka tidak ditemukan"<<endl;
    }

    delete arr;

}

main()
{
      int ukuran,nilai;
      cout<<"Program Pencarian dan Pengurutan :"<<endl;
      cout<<endl;
      cout<<"Masukkan jumlah array yang diinputkan :";
      cin>>ukuran;

      utama a(ukuran);    	/// inisialisasi obyek a dari class utama
          	     a.insert();
      	     a.baca();
                   a.pengurutan();
                   a.baca();


      cout<<"apakah anda ingin melakukan pencarian "<<endl;
      cout<<"Jika iya masukkan angka, jika tidak tekan -88 :"<<endl;
      cin>>nilai;

      if(nilai!=-88)
      {
	               a.pencarian(nilai);
      }else
      {
      	cout<<"Thanks and bye-bye"<<endl;
      }

}

