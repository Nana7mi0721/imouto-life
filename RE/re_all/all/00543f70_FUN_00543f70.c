
uint FUN_00543f70(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  if (DAT_00a37d78 == 1) {
    return ((param_1 | 0xffffff00) << 8 | param_2) << 8 | param_3;
  }
  iVar1 = FUN_00581c90(DAT_00a37e70 != 0x10,0,0);
  return ((uint)((byte)param_3 >> (8U - *(char *)(iVar1 + 10) & 0x1f)) <<
         (*(byte *)(iVar1 + 0xe) & 0x1f)) +
         ((uint)((byte)param_2 >> (8U - *(char *)(iVar1 + 9) & 0x1f)) <<
         (*(byte *)(iVar1 + 0xd) & 0x1f)) +
         ((uint)((byte)param_1 >> (8U - *(char *)(iVar1 + 8) & 0x1f)) <<
         (*(byte *)(iVar1 + 0xc) & 0x1f)) + *(int *)(iVar1 + 0x20);
}

