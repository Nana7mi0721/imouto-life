
int FUN_004d7d60(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  iterator *this;
  undefined4 local_18;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined4 local_8;
  
  iVar1 = FUN_004cd730();
  if (iVar1 == 0) {
    local_18 = 0;
  }
  else {
    uVar2 = FUN_004ce060(local_c);
    local_18 = FUN_004e4c20(uVar2);
  }
  local_8 = local_18;
  FUN_004e2ac0(param_2,1,param_3);
  iVar1 = param_1;
  this = (iterator *)FUN_004ce060(local_10);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::iterator::operator+
            (this,iVar1);
  return param_1;
}

