
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0044afb0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  
  if (param_4 == 0) {
    FUN_0047eca0(_DAT_00829868,param_2);
    uVar1 = FUN_004fe844();
    *(undefined4 *)(param_1 + 0x18a8) = uVar1;
    FUN_0047eca0(_DAT_00829868,param_3);
    uVar1 = FUN_004fe844();
    *(undefined4 *)(param_1 + 0x18ac) = uVar1;
    *(int *)(param_1 + 0x18b4) = param_5 + 1;
    *(undefined4 *)(param_1 + 0x18c8) = 1;
  }
  if (param_4 == 1) {
    FUN_0047eca0(_DAT_00829868,param_2);
    uVar1 = FUN_004fe844();
    *(undefined4 *)(param_1 + 0x18a0) = uVar1;
    FUN_0047eca0(_DAT_00829868,param_3);
    uVar1 = FUN_004fe844();
    *(undefined4 *)(param_1 + 0x18a4) = uVar1;
    *(int *)(param_1 + 0x18b0) = param_5 + 1;
    *(undefined4 *)(param_1 + 0x18c4) = 1;
  }
  return;
}

