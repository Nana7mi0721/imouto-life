
undefined4 FUN_005dc1e0(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  uint uVar7;
  byte bStack_4a;
  undefined1 uStack_49;
  char cStack_48;
  byte bStack_47;
  undefined1 auStack_46 [2];
  uint uStack_44;
  int local_40;
  uint uStack_3c;
  uint local_38;
  int iStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  uint uStack_18;
  uint uStack_14;
  int iStack_10;
  undefined4 uStack_c;
  int iStack_8;
  undefined1 uStack_4;
  undefined2 local_3;
  undefined1 local_1;
  
  uVar1 = param_1;
  *(undefined4 *)(param_1 + 0x4a) = 0;
  *(undefined4 *)(param_1 + 0x56) = 0;
  *(undefined4 *)(param_1 + 0x62) = 0;
  *(undefined4 *)(param_1 + 0x6a) = 0;
  *(undefined4 *)(param_1 + 0x66) = 0;
  uStack_18 = (uint)(byte)uStack_18;
  uStack_14 = 0;
  iStack_10 = 0;
  uStack_c = 0;
  iStack_8 = 0;
  uStack_4 = 0;
  local_3 = 0;
  local_1 = 0;
  local_40 = -1;
  local_38 = 0xffffffff;
  (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x24),0,0,2);
  iVar2 = (**(code **)(uVar1 + 0xc))(*(undefined4 *)(uVar1 + 0x24));
  iStack_34 = iVar2;
  (**(code **)(uVar1 + 0x10))(*(undefined4 *)(uVar1 + 0x24),0,0,0);
  uStack_3c = uStack_3c & 0xffffff;
  (**(code **)(uVar1 + 0x14))(&uStack_3c,1,3,*(undefined4 *)(uVar1 + 0x24));
  iVar3 = FUN_0056d100(&uStack_3c,&DAT_0080212c);
  if (iVar3 == 0) {
    (**(code **)(uVar1 + 0x14))(&param_1,1,1,*(undefined4 *)(uVar1 + 0x24));
    (**(code **)(uVar1 + 0x14))(&uStack_49,1,1,*(undefined4 *)(uVar1 + 0x24));
    (**(code **)(uVar1 + 0x14))(&bStack_4a,1,1,*(undefined4 *)(uVar1 + 0x24));
    (**(code **)(uVar1 + 0x14))(&uStack_44,1,4,*(undefined4 *)(uVar1 + 0x24));
    uStack_44 = (((uStack_44 & 0xff) * 0x80 + (uStack_44 >> 8 & 0xff)) * 0x80 +
                (uStack_44 >> 0x10 & 0xff)) * 0x80 + 10 + (uStack_44 >> 0x18);
    if (((char)param_1 == '\x04') && ((bStack_4a & 0x10) != 0)) {
      uStack_44 = uStack_44 + 10;
    }
  }
  else {
    uStack_44 = 0;
  }
  if (0x80 < iVar2) {
    param_1 = param_1 & 0xffffff;
    (**(code **)(uVar1 + 0x10))(*(undefined4 *)(uVar1 + 0x24),0xffffff80,0xffffffff,2);
    (**(code **)(uVar1 + 0x14))(&param_1,1,3,*(undefined4 *)(uVar1 + 0x24));
    iVar2 = FUN_0056d100(&param_1,&DAT_00802128);
    uStack_3c = (-(uint)(iVar2 != 0) & 0xffffff80) + 0x80;
  }
  param_1 = 0;
  uVar7 = 0;
  do {
    (**(code **)(uVar1 + 0x10))(*(undefined4 *)(uVar1 + 0x24),uStack_44,0,0);
    iVar2 = -1;
LAB_005dc390:
    do {
      do {
        iVar3 = (**(code **)(uVar1 + 0x14))(&cStack_48,1,1,*(undefined4 *)(uVar1 + 0x24));
        if (iVar3 == 0) goto LAB_005dc523;
      } while (cStack_48 != -1);
      iVar3 = (**(code **)(uVar1 + 0x14))(&bStack_47,1,1,*(undefined4 *)(uVar1 + 0x24));
      if (iVar3 == 0) goto LAB_005dc523;
    } while ((bStack_47 & 0xe0) != 0xe0);
    (**(code **)(uVar1 + 0x14))(auStack_46,1,2,*(undefined4 *)(uVar1 + 0x24));
    iVar4 = FUN_005dc090();
    iVar6 = iStack_20;
    iVar3 = iStack_28;
    if (iVar4 < 0) {
      return 0xffffffff;
    }
    if (iStack_20 == 0) {
      return 0xffffffff;
    }
    if (iVar2 == -1) {
      if (param_1 != 0) {
        if (param_1 != 1) goto LAB_005dc49a;
        if (iStack_28 != local_40) goto LAB_005dc4c7;
      }
      iVar2 = (**(code **)(uVar1 + 0xc))(*(undefined4 *)(uVar1 + 0x24));
      uStack_18 = uStack_30;
      iVar2 = iVar2 + -4;
      uStack_14 = uStack_2c;
      iStack_10 = iVar3;
      uStack_c = uStack_24;
      iStack_8 = iVar6;
      uStack_4 = (undefined1)iStack_1c;
      local_3 = (undefined2)((uint)iStack_1c >> 8);
      local_1 = (undefined1)((uint)iStack_1c >> 0x18);
LAB_005dc49a:
      if (param_1 == 0) {
        if ((local_40 < 0) || (local_40 < iVar3)) {
          local_40 = iVar3;
        }
        if (((int)local_38 < 0) || ((int)local_38 < (int)(uStack_2c >> 8 & 0xff))) {
          local_38 = uStack_2c >> 8 & 0xff;
        }
      }
    }
    else {
      if (param_1 != 1) goto LAB_005dc49a;
      if ((char)(uStack_14 >> 8) != uStack_2c._1_1_) {
        return 0xffffffff;
      }
      if (iStack_10 != iStack_28) {
        return 0xffffffff;
      }
    }
LAB_005dc4c7:
    *(int *)(uVar1 + 0x62) = *(int *)(uVar1 + 0x62) + iStack_1c;
    iVar3 = (**(code **)(uVar1 + 0xc))(*(undefined4 *)(uVar1 + 0x24));
    uVar7 = iVar3 + -4 + iVar6;
    if (uVar7 < iStack_34 - uStack_3c) {
      (**(code **)(uVar1 + 0x10))(*(undefined4 *)(uVar1 + 0x24),iVar6 + -4,0,1);
      goto LAB_005dc390;
    }
    if (iStack_34 - uStack_3c < uVar7) {
      uVar7 = iStack_34 - uStack_3c;
    }
    param_1 = param_1 + 1;
  } while ((int)param_1 < 2);
LAB_005dc523:
  if (iVar2 != -1) {
    (**(code **)(uVar1 + 0x10))(*(undefined4 *)(uVar1 + 0x24),iVar2,0,0);
    (**(code **)(uVar1 + 0x14))(&cStack_48,1,4,*(undefined4 *)(uVar1 + 0x24));
    iVar3 = FUN_005dc090();
    if (-1 < iVar3) {
      param_1 = 0x20;
      (*DAT_00f3a11c)(0,0x32,&param_1);
      puVar5 = (undefined2 *)
               FUN_0056e030(iStack_8,
                            "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxSoundConvertWin.cpp",
                            0x301);
      if (puVar5 != (undefined2 *)0x0) {
        FUN_0056d380(puVar5,0,iStack_8);
        puVar5[1] = (ushort)(byte)(local_38 >> 8);
        *(int *)(puVar5 + 2) = iStack_34;
        puVar5[0xc] = (undefined2)uStack_2c;
        *(uint *)(puVar5 + 4) = uStack_30 * 1000 >> 3;
        puVar5[8] = 0xc;
        *puVar5 = 0x55;
        puVar5[6] = 1;
        puVar5[7] = 0;
        puVar5[9] = 1;
        *(uint *)(puVar5 + 10) = local_38 & 0xff;
        puVar5[0xd] = 1;
        puVar5[0xe] = 700;
        (**(code **)(uVar1 + 0x10))(*(undefined4 *)(uVar1 + 0x24),iVar2,0,0);
        *(undefined2 **)(uVar1 + 0x4a) = puVar5;
        puVar5 = (undefined2 *)(uVar1 + 0x38);
        *(int *)(uVar1 + 0x30) = iVar2;
        *(uint *)(uVar1 + 0x34) = uVar7 - iVar2;
        FUN_0056d380(puVar5,0,0x12);
        *puVar5 = 1;
        iVar3 = (*DAT_00f3a114)(0,*(undefined4 *)(uVar1 + 0x4a),puVar5,0x12,0x10000);
        if (iVar3 == 0) {
          *(undefined4 *)(uVar1 + 0x5a) = *(undefined4 *)(uVar1 + 0x34);
          iVar3 = FUN_0056e030(*(undefined4 *)(uVar1 + 0x34),
                               "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxSoundConvertWin.cpp"
                               ,0x330);
          *(int *)(uVar1 + 0x56) = iVar3;
          if (iVar3 != 0) {
            (**(code **)(uVar1 + 0x14))
                      (iVar3,*(undefined4 *)(uVar1 + 0x34),1,*(undefined4 *)(uVar1 + 0x24));
            (**(code **)(uVar1 + 0x10))(*(undefined4 *)(uVar1 + 0x24),iVar2,0,0);
            *(undefined4 *)(uVar1 + 0x5e) = 0;
            iVar3 = 0;
            iVar2 = uVar1 + 0x4e;
            do {
              iVar6 = (*DAT_00f3a110)(iVar2,0,*(undefined4 *)(uVar1 + 0x4a),puVar5,0,0,0,4);
              if (iVar6 != 0) goto LAB_005dc6f9;
              iVar3 = iVar3 + 1;
              iVar2 = iVar2 + 4;
            } while (iVar3 < 2);
            uVar7 = (uint)(*(int *)(uVar1 + 0x40) * 4) / 3;
            *(uint *)(uVar1 + 0x450) = uVar7;
            iVar2 = FUN_0056e030(uVar7,
                                 "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxSoundConvertWin.cpp"
                                 ,0x34c);
            *(int *)(uVar1 + 0x6e) = iVar2;
            if (iVar2 != 0) {
              *(undefined4 *)(uVar1 + 8) = 3;
              return 0;
            }
          }
        }
      }
LAB_005dc6f9:
      if (*(int *)(uVar1 + 0x4e) != 0) {
        (*DAT_00f3a118)(*(int *)(uVar1 + 0x4e),0);
        *(undefined4 *)(uVar1 + 0x4e) = 0;
      }
      if (*(int *)(uVar1 + 0x52) != 0) {
        (*DAT_00f3a118)(*(int *)(uVar1 + 0x52),0);
        *(undefined4 *)(uVar1 + 0x52) = 0;
      }
      if (*(int *)(uVar1 + 0x6e) != 0) {
        FUN_0056e1d0(*(int *)(uVar1 + 0x6e));
        *(undefined4 *)(uVar1 + 0x6e) = 0;
      }
      if (*(int *)(uVar1 + 0x4a) != 0) {
        FUN_0056e1d0(*(int *)(uVar1 + 0x4a));
        *(undefined4 *)(uVar1 + 0x4a) = 0;
      }
      if (*(int *)(uVar1 + 0x56) != 0) {
        FUN_0056e1d0(*(int *)(uVar1 + 0x56));
        *(undefined4 *)(uVar1 + 0x56) = 0;
      }
    }
  }
  return 0xffffffff;
}

