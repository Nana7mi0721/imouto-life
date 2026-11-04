
void FUN_007a2540(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  
  iVar1 = FUN_007a22e0(param_3 - 1U);
  if (iVar1 < 9) {
    FUN_007a2390(param_1,param_2,param_2 + 1,param_3);
    return;
  }
  bVar3 = (byte)(iVar1 + -8);
  uVar2 = param_2 >> (bVar3 & 0x1f);
  FUN_007a2390(param_1,uVar2,uVar2 + 1,(param_3 - 1U >> (bVar3 & 0x1f)) + 1);
  FUN_007a25b0(param_1,(1 << (bVar3 & 0x1f)) - 1U & param_2,iVar1 + -8);
  return;
}

