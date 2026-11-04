
int FUN_007a2340(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = FUN_007a22e0(*(undefined4 *)(param_1 + 0x1c));
  uVar4 = *(uint *)(param_1 + 0x1c) >> ((char)iVar2 - 0x10U & 0x1f);
  iVar3 = (uVar4 >> 0xc) - 8;
  return ((iVar2 * -8 - (uint)(*(uint *)(&DAT_00838aa4 + iVar3 * 4) < uVar4)) - iVar3) + iVar1 * 8;
}

