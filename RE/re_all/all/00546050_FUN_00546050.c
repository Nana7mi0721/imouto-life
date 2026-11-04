
undefined4 FUN_00546050(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_24;
  undefined4 *local_20;
  int iStack_1c;
  undefined1 local_10 [4];
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  local_20 = (undefined4 *)0x0;
  local_24 = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  iVar2 = (**(code **)(param_1 + 8))(local_10,0x10,1,uVar1);
  if (((iVar2 == 0) || (iVar2 = FUN_0056d3d0(local_10,&DAT_007d5f04,4), iVar2 != 0)) ||
     ((iStack_c != 0x10101010 && (iStack_c != 0x8080808)))) {
    return 0xffffffff;
  }
  iVar2 = ((uint)(iStack_c == 0x10101010) * 4 + 4) * iStack_8;
  if (param_3 != 0) goto LAB_005461c8;
  local_20 = (undefined4 *)
             FUN_0056e030(iStack_4 * iStack_8 * 4,
                          "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xe6d);
  if (local_20 != (undefined4 *)0x0) {
    if (iStack_c == 0x10101010) {
      local_24 = FUN_0056e030(iVar2,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xe7a);
      if (local_24 != 0) {
        iStack_1c = 0;
        if (0 < iStack_4) {
          puVar6 = local_20;
          do {
            iVar3 = (**(code **)(param_1 + 8))(local_24,iVar2,1,uVar1);
            if (iVar3 == 0) goto LAB_0054623b;
            if (0 < iStack_8) {
              puVar4 = (undefined1 *)(local_24 + 5);
              iVar3 = iStack_8;
              puVar5 = puVar6;
              do {
                puVar6 = puVar5 + 1;
                iVar3 = iVar3 + -1;
                *puVar5 = CONCAT31(CONCAT21(CONCAT11(puVar4[2],*puVar4),puVar4[-2]),puVar4[-4]);
                puVar4 = puVar4 + 8;
                puVar5 = puVar6;
              } while (iVar3 != 0);
            }
            iStack_1c = iStack_1c + 1;
          } while (iStack_1c < iStack_4);
        }
        FUN_0056e1d0(local_24);
LAB_005461c8:
        *(undefined4 **)(param_2 + 0x434) = local_20;
        *(int *)(param_2 + 0x428) = iStack_8;
        *(int *)(param_2 + 0x42c) = iStack_4;
        *(int *)(param_2 + 0x430) = iStack_8 * 4;
        FUN_00544560(param_2);
        *(undefined1 *)(param_2 + 5) = 0x20;
        *(undefined1 *)(param_2 + 4) = 4;
        *(undefined1 *)(param_2 + 0xf) = 0x18;
        *(undefined4 *)(param_2 + 0x1c) = 0xff000000;
        *(undefined1 *)(param_2 + 0xb) = 8;
        return 0;
      }
    }
    else {
      iVar2 = (**(code **)(param_1 + 8))(local_20,iStack_4 * iStack_8 * 4,1,uVar1);
      if (iVar2 != 0) goto LAB_005461c8;
    }
LAB_0054623b:
    FUN_0056e1d0(local_20);
    if (local_24 != 0) {
      FUN_0056e1d0(local_24);
    }
  }
  return 0xffffffff;
}

