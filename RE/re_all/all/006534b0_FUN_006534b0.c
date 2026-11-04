
void FUN_006534b0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((*(int *)(param_1 + 0x290) != 0) && (*(int *)(param_1 + 0x294) != 0)) {
    uVar3 = 0;
    if (*(int *)(param_1 + 0x294) != 0) {
      do {
        iVar2 = *(int *)(*(int *)(param_1 + 0x290) + uVar3 * 4);
        if ((*(short *)(iVar2 + 0x18) == 0x41) &&
           (iVar1 = _strncmp(&DAT_00a06274,*(char **)(iVar2 + 0x1c),4), iVar1 == 0)) {
          FUN_006507e0(*(undefined4 *)(iVar2 + 0x1c));
          FUN_006507e0(iVar2);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(param_1 + 0x294));
    }
    FUN_006507e0(*(undefined4 *)(param_1 + 0x290));
    *(undefined4 *)(param_1 + 0x290) = 0;
    *(undefined4 *)(param_1 + 0x294) = 0;
  }
  iVar2 = FUN_00653570(param_1,*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 8));
  if (iVar2 == 0) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),s__TIFFSetupFields_00a09a74,
                 s_Setting_up_field_info_failed_00a09a88);
  }
  return;
}

