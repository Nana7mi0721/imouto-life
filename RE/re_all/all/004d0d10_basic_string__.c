
/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const &)
    public: __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >(class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > const &)
   
   Library: Visual Studio 2003 Debug */

_String_val<char,std::allocator<char>_> * __thiscall
basic_string<>(_String_val<char,std::allocator<char>_> *param_1,
              basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
              *param_2)

{
  _String_val<char,std::allocator<char>_> *p_Var1;
  
  p_Var1 = param_1;
  allocator<>(param_2);
  std::_String_val<char,std::allocator<char>_>::_String_val<char,std::allocator<char>_>
            (param_1,p_Var1);
  FID_conflict__Tidy(param_1,false,0);
  FID_conflict_assign(param_1,param_2,0,DAT_007d0624);
  return param_1;
}

