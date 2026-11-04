
uint FUN_007a21c0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = param_2 - 1;
  iVar1 = FUN_007a22e0(uVar5);
  if (iVar1 < 9) {
    uVar3 = FUN_007a2060(param_1,param_2);
    FUN_007a20e0(param_1,uVar3,uVar3 + 1,param_2);
  }
  else {
    bVar4 = (byte)(iVar1 + -8);
    iVar6 = (uVar5 >> (bVar4 & 0x1f)) + 1;
    iVar2 = FUN_007a2060(param_1,iVar6);
    FUN_007a20e0(param_1,iVar2,iVar2 + 1,iVar6);
    uVar3 = FUN_007a2250(param_1,iVar1 + -8);
    uVar3 = uVar3 | iVar2 << (bVar4 & 0x1f);
    if (uVar5 < uVar3) {
      *(undefined4 *)(param_1 + 0x2c) = 1;
      return uVar5;
    }
  }
  return uVar3;
}

