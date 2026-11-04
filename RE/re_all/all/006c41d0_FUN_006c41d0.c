
int FUN_006c41d0(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  
  if (*(code **)(param_1 + 0x21dc) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 0x21dc))
                      (*(undefined4 *)(param_1 + 0x21e0),*(undefined4 *)(param_1 + 0x21d8),param_2,
                       param_3,param_4,param_5,0x1b80,*(undefined4 *)(param_1 + 0x60));
    if (iVar1 != 0x1a40) {
      if (0 < iVar1) {
        return -0x88;
      }
      goto LAB_006c4235;
    }
  }
  iVar1 = FUN_00797ec0(*(undefined4 *)(param_1 + 0x21d8),*param_3,param_3[1],param_2,param_4,0);
LAB_006c4235:
  if (iVar1 < 0) {
    iVar1 = -0x88;
  }
  return iVar1;
}

