
void FUN_00676b80(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_400 [1024];
  
  *(int *)(param_1 + 0x90) = param_2;
  *(undefined4 *)(param_1 + 0x94) = 0;
  if (param_2 == 0) {
    param_3 = 0;
  }
  do {
    if (*(int *)(param_1 + 0x88) == 0) {
      iVar2 = *(int *)(param_1 + 0x13c);
      while (iVar2 == 0) {
        FUN_00673140(param_1,0);
        uVar1 = FUN_00673070(param_1);
        *(undefined4 *)(param_1 + 0x13c) = uVar1;
        if (*(int *)(param_1 + 0x11c) != 0x49444154) {
          FUN_00668620(param_1,s_Not_enough_image_data_00a0d264);
        }
        iVar2 = *(int *)(param_1 + 0x13c);
      }
      uVar4 = *(uint *)(param_1 + 0x2c0);
      if (*(uint *)(param_1 + 0x13c) < *(uint *)(param_1 + 0x2c0)) {
        uVar4 = *(uint *)(param_1 + 0x13c);
      }
      uVar1 = FUN_00674040(param_1,uVar4,0);
      FUN_00673110(param_1,uVar1,uVar4);
      *(undefined4 *)(param_1 + 0x84) = uVar1;
      *(uint *)(param_1 + 0x88) = uVar4;
      *(uint *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) - uVar4;
    }
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x94) = 0x400;
      *(undefined1 **)(param_1 + 0x90) = local_400;
    }
    else {
      iVar2 = -1;
      if (param_3 != -1) {
        iVar2 = param_3;
      }
      param_3 = param_3 - iVar2;
      *(int *)(param_1 + 0x94) = iVar2;
    }
    iVar2 = FUN_0067abc0(param_1 + 0x84,0);
    if (param_2 == 0) {
      iVar3 = 0x400 - *(int *)(param_1 + 0x94);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x94);
    }
    param_3 = param_3 + iVar3;
    *(undefined4 *)(param_1 + 0x94) = 0;
    if (iVar2 == 1) {
      *(undefined4 *)(param_1 + 0x90) = 0;
      *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 8;
      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 8;
      if ((*(int *)(param_1 + 0x88) != 0) || (*(int *)(param_1 + 0x13c) != 0)) {
        FUN_00668b90(param_1,s_Extra_compressed_data_00a0d24c);
      }
      if (param_3 == 0) {
        return;
      }
      if (param_2 == 0) {
        FUN_00668b90(param_1,s_Too_much_image_data_00a0d238);
        return;
      }
      FUN_00668620(param_1,s_Not_enough_image_data_00a0d264);
      return;
    }
    if (iVar2 != 0) {
      FUN_00669790(param_1,iVar2);
      if (param_2 == 0) {
        FUN_00668b90(param_1,*(undefined4 *)(param_1 + 0x9c));
        return;
      }
      FUN_00668a30(param_1,*(undefined4 *)(param_1 + 0x9c));
    }
  } while (param_3 != 0);
  return;
}

