
undefined4 FUN_005dbd80(int param_1)

{
  undefined2 *puVar1;
  short *psVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_10 [4];
  undefined1 uStack_c;
  int local_8;
  uint uStack_4;
  
  iVar6 = 0;
  *(undefined4 *)(param_1 + 0x4a) = 0;
  *(undefined4 *)(param_1 + 0x4e) = 0;
  *(undefined4 *)(param_1 + 0x52) = 0;
  *(undefined4 *)(param_1 + 0x56) = 0;
  *(undefined4 *)(param_1 + 0x62) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x6a) = 0;
  *(undefined4 *)(param_1 + 0x66) = 0;
  *(undefined4 *)(param_1 + 0x6e) = 0;
  (**(code **)(param_1 + 0x14))(&local_8,8,1,*(undefined4 *)(param_1 + 0x24));
  if (local_8 == 0x46464952) {
    uStack_c = 0;
    (**(code **)(param_1 + 0x14))(auStack_10,4,1,*(undefined4 *)(param_1 + 0x24));
    iVar3 = FUN_0056d100(auStack_10,&DAT_007d6160);
    if (iVar3 == 0) {
      (**(code **)(param_1 + 0x14))(&local_8,8,1,*(undefined4 *)(param_1 + 0x24));
      if (local_8 == 0x74786562) {
        (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x24),uStack_4,0,1);
        (**(code **)(param_1 + 0x14))(&local_8,8,1,*(undefined4 *)(param_1 + 0x24));
      }
      if (local_8 == 0x20746d66) {
        iVar3 = FUN_0056e030(uStack_4,
                             "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxSoundConvertWin.cpp"
                             ,0x141);
        *(int *)(param_1 + 0x4a) = iVar3;
        if (iVar3 != 0) {
          uVar4 = (**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 0x24));
          *(undefined4 *)(param_1 + 0x28) = uVar4;
          *(uint *)(param_1 + 0x2c) = uStack_4;
          (**(code **)(param_1 + 0x14))
                    (*(undefined4 *)(param_1 + 0x4a),uStack_4,1,*(undefined4 *)(param_1 + 0x24));
          psVar2 = *(short **)(param_1 + 0x4a);
          if ((*psVar2 == 1) && (uStack_4 == 0x10)) {
            psVar2[7] = (short)((ulonglong)(ushort)psVar2[6] /
                               (ulonglong)(longlong)(int)(uint)(ushort)psVar2[1]) * 8;
            *(undefined2 *)(*(int *)(param_1 + 0x4a) + 0x10) = 0;
          }
          iVar3 = (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_1 + 0x24));
          while ((iVar3 == 0 &&
                 ((**(code **)(param_1 + 0x14))(&local_8,8,1,*(undefined4 *)(param_1 + 0x24)),
                 local_8 != 0x61746164))) {
            (**(code **)(param_1 + 0x10))
                      (*(undefined4 *)(param_1 + 0x24),(uStack_4 & 1) + uStack_4,0,1);
            iVar3 = (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_1 + 0x24));
          }
          iVar3 = (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_1 + 0x24));
          if (iVar3 == 0) {
            uVar4 = (**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 0x24));
            puVar1 = (undefined2 *)(param_1 + 0x38);
            *(undefined4 *)(param_1 + 0x30) = uVar4;
            *(uint *)(param_1 + 0x34) = uStack_4;
            FUN_0056d380(puVar1,0,0x12);
            *puVar1 = 1;
            iVar3 = (*DAT_00f3a114)(0,*(undefined4 *)(param_1 + 0x4a),puVar1,0x12,0x10000);
            if (iVar3 == 0) {
              *(undefined4 *)(param_1 + 0x5a) = *(undefined4 *)(param_1 + 0x34);
              iVar3 = FUN_0056e030(*(undefined4 *)(param_1 + 0x34),
                                   "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxSoundConvertWin.cpp"
                                   ,0x16a);
              *(int *)(param_1 + 0x56) = iVar3;
              if (iVar3 != 0) {
                *(undefined4 *)(param_1 + 0x5e) = 0;
                (**(code **)(param_1 + 0x14))
                          (iVar3,*(undefined4 *)(param_1 + 0x34),1,*(undefined4 *)(param_1 + 0x24));
                (**(code **)(param_1 + 0x10))
                          (*(undefined4 *)(param_1 + 0x24),*(int *)(param_1 + 0x30),
                           *(int *)(param_1 + 0x30) >> 0x1f,0);
                iVar3 = param_1 + 0x4e;
                do {
                  iVar5 = (*DAT_00f3a110)(iVar3,0,*(undefined4 *)(param_1 + 0x4a),puVar1,0,0,0,4);
                  if (iVar5 != 0) goto LAB_005dc00c;
                  iVar6 = iVar6 + 1;
                  iVar3 = iVar3 + 4;
                } while (iVar6 < 2);
                *(undefined4 *)(param_1 + 0x450) = *(undefined4 *)(param_1 + 0x40);
                iVar6 = FUN_0056e030(*(undefined4 *)(param_1 + 0x40),
                                     "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxSoundConvertWin.cpp"
                                     ,0x186);
                *(int *)(param_1 + 0x6e) = iVar6;
                if (iVar6 != 0) {
                  *(undefined4 *)(param_1 + 8) = 3;
                  return 0;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_005dc00c:
  if (*(int *)(param_1 + 0x4e) != 0) {
    (*DAT_00f3a118)(*(int *)(param_1 + 0x4e),0);
    *(undefined4 *)(param_1 + 0x4e) = 0;
  }
  if (*(int *)(param_1 + 0x52) != 0) {
    (*DAT_00f3a118)(*(int *)(param_1 + 0x52),0);
    *(undefined4 *)(param_1 + 0x52) = 0;
  }
  if (*(int *)(param_1 + 0x6e) != 0) {
    FUN_0056e1d0(*(int *)(param_1 + 0x6e));
    *(undefined4 *)(param_1 + 0x6e) = 0;
  }
  if (*(int *)(param_1 + 0x4a) != 0) {
    FUN_0056e1d0(*(int *)(param_1 + 0x4a));
    *(undefined4 *)(param_1 + 0x4a) = 0;
  }
  if (*(int *)(param_1 + 0x56) != 0) {
    FUN_0056e1d0(*(int *)(param_1 + 0x56));
    *(undefined4 *)(param_1 + 0x56) = 0;
  }
  return 0xffffffff;
}

