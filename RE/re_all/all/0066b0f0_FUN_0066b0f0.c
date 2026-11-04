
undefined4 FUN_0066b0f0(int param_1,int param_2)

{
  int iVar1;
  int local_8;
  undefined4 local_4;
  
  local_4 = 0;
  local_8 = 0;
  iVar1 = FUN_0066af60(param_1,param_2,&local_4,&local_8);
  if ((iVar1 == 0) || ((local_8 != param_2 && (*(char *)(local_8 + param_1) != '\0')))) {
    return 0;
  }
  return local_4;
}

