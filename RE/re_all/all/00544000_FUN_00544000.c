
undefined4 FUN_00544000(uint param_1,uint *param_2,uint *param_3,uint *param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  if (DAT_00a37d78 == 1) {
    *param_2 = param_1 >> 0x10 & 0xff;
    *param_3 = param_1 >> 8 & 0xff;
    *param_4 = param_1 & 0xff;
    return 0;
  }
  iVar3 = FUN_00581c90(DAT_00a37e70 != 0x10,0,0);
  bVar1 = *(byte *)(iVar3 + 9);
  bVar2 = *(byte *)(iVar3 + 10);
  *param_2 = (((*(uint *)(iVar3 + 0x10) & param_1) >> (*(byte *)(iVar3 + 0xc) & 0x1f)) * 0xff) /
             ((1 << (*(byte *)(iVar3 + 8) & 0x1f)) - 1U);
  *param_3 = (((*(uint *)(iVar3 + 0x14) & param_1) >> (*(byte *)(iVar3 + 0xd) & 0x1f)) * 0xff) /
             ((1 << (bVar1 & 0x1f)) - 1U);
  *param_4 = (((*(uint *)(iVar3 + 0x18) & param_1) >> (*(byte *)(iVar3 + 0xe) & 0x1f)) * 0xff) /
             ((1 << (bVar2 & 0x1f)) - 1U);
  return 0;
}

