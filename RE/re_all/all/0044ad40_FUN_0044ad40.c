
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0044ad40(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int local_38;
  undefined4 local_34;
  undefined4 local_20;
  
  *(uint *)(param_1 + 0x1664) = (uint)(0 < param_2) * 2 + 4;
  *(uint *)(param_1 + 0x1668) = ((param_3 < 1) - 1 & 0xfffffffa) + 8;
  uVar1 = FUN_004febf1(param_2);
  *(undefined4 *)(param_1 + 0x166c) = uVar1;
  uVar1 = FUN_004febf1(param_3);
  *(undefined4 *)(param_1 + 0x1670) = uVar1;
  FUN_004fed84((double)(param_2 * param_2 + param_3 * param_3));
  if (param_4 != 8) {
    FUN_0047eca0((int)_DAT_00829868,(int)((ulonglong)_DAT_00829868 >> 0x20),
                 (param_4 + 1) - (uint)(8 < param_4));
    FUN_004fe844();
  }
  FUN_004febf1(param_2);
  iVar2 = FUN_004fe844();
  if (iVar2 < 1) {
    local_20 = 1;
  }
  else {
    if (param_4 != 8) {
      FUN_0047eca0((int)_DAT_00829868,(int)((ulonglong)_DAT_00829868 >> 0x20),
                   (param_4 + 1) - (uint)(8 < param_4));
      FUN_004fe844();
    }
    FUN_004febf1(param_2);
    local_20 = FUN_004fe844();
  }
  *(undefined4 *)(param_1 + 0x1674) = local_20;
  if (param_4 != 8) {
    FUN_0047eca0((int)_DAT_00829868,(int)((ulonglong)_DAT_00829868 >> 0x20),
                 (param_4 + 1) - (uint)(8 < param_4));
    FUN_004fe844();
  }
  FUN_004febf1(param_3);
  iVar2 = FUN_004fe844();
  if (iVar2 < 1) {
    local_34 = 1;
  }
  else {
    if (param_4 == 8) {
      local_38 = DAT_0084b264 * 2 * *(int *)(param_1 + 0x1670);
    }
    else {
      FUN_0047eca0((int)_DAT_00829868,(int)((ulonglong)_DAT_00829868 >> 0x20),
                   (param_4 + 1) - (uint)(8 < param_4));
      local_38 = FUN_004fe844();
    }
    iVar2 = FUN_004febf1(param_3);
    local_34 = FUN_004fe844(iVar2 * local_38);
  }
  *(undefined4 *)(param_1 + 0x1678) = local_34;
  return;
}

