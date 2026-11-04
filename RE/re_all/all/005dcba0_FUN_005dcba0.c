
undefined4 FUN_005dcba0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined4 local_2c;
  undefined8 uStack_28;
  undefined4 uStack_1c;
  undefined1 auStack_18 [8];
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  iVar5 = param_1;
  piVar1 = (int *)(param_1 + 0x4a);
  puVar2 = (undefined4 *)(param_1 + 0xc);
  param_1 = 0;
  local_2c = 0;
  if ((((((DAT_00aba204 == 0) || (DAT_00aba224 == 0)) || (DAT_00aba208 == (code *)0x0)) ||
       ((DAT_00aba228 == 0 || (DAT_00aba210 == (code *)0x0)))) ||
      ((DAT_00aba218 == 0 || ((DAT_00aba21c == 0 || (DAT_00aba220 == 0)))))) ||
     (DAT_00aba214 == (code *)0x0)) {
    return 0xffffffff;
  }
  uVar10 = (*(code *)*puVar2)(*(undefined4 *)(iVar5 + 0x24));
  uStack_1c = (undefined4)((ulonglong)uVar10 >> 0x20);
  (**(code **)(iVar5 + 0x10))(*(undefined4 *)(iVar5 + 0x24),0,0,2);
  uStack_28 = (*(code *)*puVar2)(*(undefined4 *)(iVar5 + 0x24));
  (**(code **)(iVar5 + 0x10))(*(undefined4 *)(iVar5 + 0x24),(int)uVar10,uStack_1c,0);
  piVar3 = (int *)(iVar5 + 0x52);
  *piVar1 = 0;
  *(undefined4 *)(iVar5 + 0x4e) = 0;
  *piVar3 = 0;
  *(undefined4 *)(iVar5 + 0x56) = 0;
  *(undefined4 *)(iVar5 + 0x66) = 0;
  if (DAT_00ca3a30 == 0) {
    DAT_00ca3a30 = 1;
    iVar7 = (*DAT_00aba208)(0x20070,0);
    if (iVar7 != 0) goto LAB_005dce53;
  }
  iVar7 = FUN_0060ab90(puVar2,uStack_28);
  *(int *)(iVar5 + 0x56) = iVar7;
  if (iVar7 != 0) {
    FUN_0060aa50();
    iVar7 = (*DAT_00aba22c)(*(undefined4 *)(iVar5 + 0x56),0,piVar1);
    if (iVar7 == 0) {
      (*DAT_00aba210)(piVar3);
      (**(code **)(*(int *)*piVar3 + 0x60))((int *)*piVar3,&DAT_0085f434,&DAT_0085f394);
      (**(code **)(*(int *)*piVar3 + 0x60))((int *)*piVar3,&DAT_0085f444,&DAT_0085f594);
      iVar7 = (**(code **)(*(int *)*piVar1 + 0x1c))((int *)*piVar1,0xfffffffd,0,*piVar3);
      if (iVar7 == 0) {
        iVar7 = (**(code **)(*(int *)*piVar1 + 0x18))((int *)*piVar1,0xfffffffd,iVar5 + 0x4e);
        if (iVar7 == 0) {
          iVar7 = (**(code **)(*(int *)*piVar1 + 0x10))((int *)*piVar1,0xfffffffd,1);
          if (iVar7 == 0) {
            iVar7 = (*DAT_00aba214)(*(undefined4 *)(iVar5 + 0x4e),&param_1,&local_2c,0);
            if (iVar7 == 0) {
              iVar7 = (**(code **)(*(int *)*piVar1 + 0x30))
                                ((int *)*piVar1,0xffffffff,&DAT_0085f424,auStack_18);
              if (iVar7 == 0) {
                *(undefined4 *)(iVar5 + 0x5a) = uStack_10;
                *(undefined4 *)(iVar5 + 0x5e) = uStack_c;
                *(undefined4 *)(iVar5 + 0x62) = 0x1000;
                iVar8 = FUN_0056e030(0x1000,
                                     "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxSoundConvertWin.cpp"
                                     ,0x5a8);
                iVar7 = param_1;
                *(int *)(iVar5 + 0x66) = iVar8;
                if (iVar8 != 0) {
                  *(undefined4 *)(iVar5 + 0x6e) = 0;
                  *(undefined4 *)(iVar5 + 0x6a) = 0;
                  *(undefined2 *)(iVar5 + 0x48) = 0;
                  *(undefined2 *)(iVar5 + 0x38) = 1;
                  *(undefined2 *)(iVar5 + 0x3a) = *(undefined2 *)(param_1 + 2);
                  iVar8 = *(int *)(param_1 + 4);
                  *(int *)(iVar5 + 0x3c) = iVar8;
                  uVar6 = *(ushort *)(param_1 + 0xe);
                  *(ushort *)(iVar5 + 0x46) = uVar6;
                  uVar6 = (uVar6 >> 3) * *(short *)(iVar5 + 0x3a);
                  iVar8 = (uint)uVar6 * iVar8;
                  *(ushort *)(iVar5 + 0x44) = uVar6;
                  *(int *)(iVar5 + 0x40) = iVar8;
                  *(undefined4 *)(iVar5 + 0x450) = 0x1000;
                  uVar10 = __allmul(iVar8,0,*(undefined4 *)(iVar5 + 0x5a),
                                    *(undefined4 *)(iVar5 + 0x5e));
                  uVar9 = __aulldiv(uVar10,&DAT_00989680,0);
                  *(undefined4 *)(iVar5 + 0x34) = uVar9;
                  *(undefined4 *)(iVar5 + 8) = 5;
                  (*DAT_00aba198)(iVar7);
                  return 0;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_005dce53:
  piVar4 = (int *)*piVar1;
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
    *piVar1 = 0;
  }
  piVar1 = *(int **)(iVar5 + 0x4e);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(iVar5 + 0x4e) = 0;
  }
  piVar1 = (int *)*piVar3;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *piVar3 = 0;
  }
  piVar1 = *(int **)(iVar5 + 0x56);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(iVar5 + 0x56) = 0;
  }
  if (*(int *)(iVar5 + 0x66) != 0) {
    FUN_0056e1d0(*(int *)(iVar5 + 0x66));
    *(undefined4 *)(iVar5 + 0x66) = 0;
  }
  if (param_1 != 0) {
    (*DAT_00aba198)(param_1);
  }
  return 0xffffffff;
}

