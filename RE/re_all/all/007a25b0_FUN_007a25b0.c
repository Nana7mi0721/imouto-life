
void FUN_007a25b0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x10);
  uVar2 = *(uint *)(param_1 + 0xc);
  if (0x20 < (uint)(iVar3 + param_3)) {
    do {
      uVar1 = FUN_007a2610(param_1,uVar2 & 0xff);
      iVar3 = iVar3 + -8;
      uVar2 = uVar2 >> 8;
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | uVar1;
    } while (7 < iVar3);
  }
  *(int *)(param_1 + 0x10) = iVar3 + param_3;
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + param_3;
  *(uint *)(param_1 + 0xc) = uVar2 | param_2 << ((byte)iVar3 & 0x1f);
  return;
}

