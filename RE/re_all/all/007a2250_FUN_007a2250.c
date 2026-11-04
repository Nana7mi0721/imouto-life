
uint FUN_007a2250(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x10);
  uVar2 = *(uint *)(param_1 + 0xc);
  uVar3 = uVar4;
  if (uVar4 < param_2) {
    do {
      iVar1 = FUN_007a22b0(param_1);
      uVar4 = uVar3 + 8;
      uVar2 = uVar2 | iVar1 << ((byte)uVar3 & 0x1f);
      uVar3 = uVar4;
    } while ((int)uVar4 < 0x19);
  }
  *(uint *)(param_1 + 0x10) = uVar4 - param_2;
  *(uint *)(param_1 + 0xc) = uVar2 >> ((byte)param_2 & 0x1f);
  *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + param_2;
  return (1 << ((byte)param_2 & 0x1f)) - 1U & uVar2;
}

