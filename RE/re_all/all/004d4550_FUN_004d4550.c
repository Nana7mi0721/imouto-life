
int __thiscall
FUN_004d4550(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,int param_2,
            undefined4 param_3,char param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  iterator *this;
  int iVar3;
  
  puVar1 = (undefined4 *)
           std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin(param_1);
  uVar2 = FUN_004e0410(param_3,*puVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::insert
            (param_1,uVar2,1,param_4);
  iVar3 = param_2;
  this = (iterator *)
         std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin(param_1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::iterator::operator+
            (this,iVar3);
  return param_2;
}

