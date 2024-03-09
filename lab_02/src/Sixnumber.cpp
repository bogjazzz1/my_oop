#include "../include/Sixnumber.hpp"

Six::Six():_size{1}{
_array = new unsigned char[1];
_array[0]='0';
};
void Six::shrink(){
    size_t r=_size;
for(size_t i=_size;i>0;--i){
        if(_array[i-1]!='0'){
                r=i;
            break;
        }
        r=i;

}
if(r==0){
    delete []_array;
    _array = new unsigned char[1];
    _size=1;
    return;
}
unsigned char *_temp_array= new unsigned char[r];
for(size_t i{0};i<r;++i) _temp_array[i] = _array[i];
delete []_array;
_array=_temp_array;
_size=r;
return;
}
Six::Six(const size_t &n,unsigned char t){
    if(t-'0'>=6){ throw std::logic_error("not 0-5 number");}
     _array = new unsigned char[n];
    for (size_t i = 0; i < n; ++i)
        _array[i] = t;
    _size = n;
    shrink();
}
Six::Six(const std::string &t){
    _array = new unsigned char[t.size()];
    size_t o{0};
    for(size_t i=t.size();i>0;--i){
            if(t[i-1]-'0'>=6){ delete [] _array;throw std::logic_error("not 0-5 number");}
 _array[o]=(static_cast<unsigned char>(t [i-1]));
 ++o;
}

_size=t.size();
shrink();
}
Six::Six(const std::initializer_list< unsigned char> &t){
_array = new unsigned char[t.size()];
    size_t i{0};
    for (auto c : t){
            if(c-'0'>=6){ delete [] _array;throw std::logic_error("not 0-5 number");}
        _array[i] = c;
        ++i;
    }
    _size = t.size();
    shrink();
}
Six::Six(const Six& other){
     _size  = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0};i<_size;++i) _array[i] = other._array[i];
    shrink();
}
Six::Six(Six&& other) noexcept{
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
    shrink();
}
Six::~Six() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}
bool Six::operator==(const Six &other) const{
if(_size!=other._size){
    return false;
}
for(size_t i=0;i<_size;++i){
    if(_array[i]!=other._array[i]){
        return false;
    }
}
return true;
}
bool Six::operator!=(const Six &other) const{
return !(*this==other);
}
std::ostream &operator<<(std::ostream &out, const Six &x){
 for (size_t i = x._size ; i >0; --i)
        out << x._array[i-1];
    return out;
}
bool Six::operator>(const Six &other) const{
    if(_size>other._size){
        return true;
    }
     if(_size<other._size){
        return false;
    }
    for(size_t i=_size;i>0;--i){
        if(_array[i-1]>other._array[i-1]){
            return true;
        }
         if(_array[i-1]<other._array[i-1]){
            return false;
        }
    }
    return false;
}
bool Six::operator<(const Six &other) const{
    if(_size>other._size){
        return false;
    }
     if(_size<other._size){
        return true;
    }
    for(size_t i=_size;i>0;--i){
        if(_array[i-1]>other._array[i-1]){
            return false;
        }
         if(_array[i-1]<other._array[i-1]){
            return true;
        }
    }
    return false;
}
Six& Six::operator +=(const Six &other){
unsigned char *temp_arr=new unsigned char[std::max(_size,other._size)+1];
size_t max_s=std::max(_size,other._size);
temp_arr[max_s]='0';
int64_t remain=0;
for(size_t i=0;i<max_s;++i){
    if(i<_size){
        remain+=_array[i]-'0';
    }
    if(i<other._size){
        remain+=other._array[i]-'0';
    }
    temp_arr[i]=(remain%6)+'0';
    remain/=6;
}
if(remain!=0){
temp_arr[max_s]=remain+'0';
}
delete[] _array;
_size=max_s+1;
_array=temp_arr;
shrink();
return *this;

};
Six Six::operator +(const Six&other) const{
Six tmp(*this);
tmp+=other;
return tmp;
}
Six& Six::operator -=(const Six&other){
if(*this<other){throw std::logic_error("Six can only operate  with not negative numbers");}
int64_t taking=0;
for(size_t i=0;i<other._size;++i){
        int64_t temp_int=_array[i]-other._array[i]-taking;
if(temp_int<0){
    temp_int=(6+temp_int)%6 ;
taking=1;
}
else{
    taking =0;
}
_array[i]=temp_int+'0';
}
for(size_t i=other._size;i<_size;++i){
        int64_t temp_int=_array[i]-taking-'0';
if(temp_int<0){
    temp_int=(6+temp_int)%6 ;
taking=1;
}
else{
    taking =0;
}
_array[i]=temp_int+'0';
}
if(taking>0){ throw std::logic_error("Six can only operate  with not negative numbers");}
shrink();
return *this;
}
Six Six::operator -(const Six&other) const{
Six tmp(*this);
tmp-=other;
return tmp;
}

