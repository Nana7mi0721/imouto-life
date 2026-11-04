
int FUN_00797960(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 < 1) || (param_1 < param_2)) || (param_2 < 0)) {
    return 0;
  }
  iVar1 = FUN_00798960(2);
  iVar2 = FUN_00798960(1);
  return ((iVar2 + 3U >> 2) * (param_1 - param_2) + (iVar1 + 3U >> 2) * param_2) * 4 + 0x10c;
}

