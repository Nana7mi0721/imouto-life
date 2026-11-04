
void __fastcall FUN_00476150(int param_1)

{
  undefined4 uVar1;
  
  FUN_00515700(*(undefined4 *)(param_1 + 0x104),0);
  FUN_00515700(*(undefined4 *)(param_1 + 0x10c),0);
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0xffffffff;
  uVar1 = FUN_00525ee0(*DAT_00a16718 * DAT_0084b248,*DAT_00a1671c * DAT_0084b248,0);
  *(undefined4 *)(param_1 + 0x104) = uVar1;
  uVar1 = FUN_00525ee0(*DAT_00a16718 * DAT_0084b248,*DAT_00a1671c * DAT_0084b248,0);
  *(undefined4 *)(param_1 + 0x10c) = uVar1;
  return;
}

