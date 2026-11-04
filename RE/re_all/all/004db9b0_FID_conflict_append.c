
/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > & __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::append(unsigned
   int,unsigned short)
    public: class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > & __thiscall std::basic_string<wchar_t,struct
   std::char_traits<wchar_t>,class std::allocator<wchar_t> >::append(unsigned int,wchar_t)
   
   Library: Visual Studio 2003 Debug */

basic_string<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
* __thiscall FID_conflict_append(void *this,uint param_1,ushort param_2)

{
  bool bVar1;
  uint uVar2;
  undefined2 extraout_var;
  undefined4 uVar3;
  wchar_t *pwVar4;
  
  if ((uint)(DAT_007d0624 - *(int *)((int)this + 0x14)) <= param_1) {
    FUN_0050d54e();
  }
  if (param_1 != 0) {
    uVar2 = *(int *)((int)this + 0x14) + param_1;
    bVar1 = FID_conflict__Grow(this,uVar2,false);
    if (bVar1) {
      uVar3 = CONCAT22(extraout_var,param_2);
      pwVar4 = FID_conflict__Myptr(this);
      assign(pwVar4 + *(int *)((int)this + 0x14),param_1,uVar3);
      FID_conflict__Eos(this,uVar2);
    }
  }
  return this;
}

