
undefined4
FUN_00562880(uint param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_4c4;
  uint local_4c0;
  int local_4bc;
  int *local_4b8;
  int local_4b4;
  undefined4 local_4b0;
  int local_4ac;
  int local_4a8;
  int local_4a4;
  undefined4 local_4a0;
  undefined4 local_49c;
  undefined4 local_498;
  uint local_494;
  undefined4 local_490;
  undefined2 local_48c;
  undefined4 local_488;
  undefined4 local_484;
  undefined4 local_480;
  undefined4 local_47c;
  undefined4 local_478;
  undefined4 local_474;
  int local_470;
  undefined4 local_46c [283];
  
  local_4ac = -1;
  iVar1 = FUN_0057e0e0();
  if ((iVar1 == 0) || (10 < param_4)) {
    return 0xffffffff;
  }
  local_46c[0] = 0;
  local_470 = 0;
  local_4c4 = 0;
  iVar1 = *(int *)(DAT_00cc4db4 + (param_1 & 0xffff) * 4);
  if ((*(int *)(in_EAX + 0xc) != 0) || (*(int *)(in_EAX + 0x14) != 0)) {
    iVar1 = FUN_005523f0();
    local_4ac = iVar1;
    if (iVar1 < 0) {
      FUN_0056bc50(L"LoadSoundMemByMemImageBase Error 1");
    }
    else {
      iVar3 = FUN_0055eb30(param_1);
      if (-1 < iVar3) {
        FUN_005525d0(iVar1);
        return 0;
      }
      FUN_0056bc50(L"LoadSoundMemByMemImageBase Error %d",-iVar3);
    }
    goto LAB_00562cf6;
  }
  if (*(int *)(in_EAX + 8) == 0) {
    local_4a8 = -1;
    local_4a4 = -1;
    local_470 = FUN_0052d000(param_2,param_3);
    puVar2 = (undefined4 *)FUN_0052c7a0();
    local_488 = *puVar2;
    local_484 = puVar2[1];
    local_480 = puVar2[2];
    local_47c = puVar2[3];
    local_478 = puVar2[4];
    local_474 = puVar2[5];
    iVar3 = FUN_00597260(local_46c,&local_488,*(undefined4 *)(in_EAX + 0x30),
                         *(undefined4 *)(in_EAX + 0x34),*(undefined4 *)(in_EAX + 0x38));
    if (iVar3 < 0) {
      FUN_0056bca0(&DAT_007d6a10);
      goto LAB_00562cf6;
    }
    iVar3 = FUN_005971c0(local_46c,&local_49c,&local_4c4,&local_4c0);
    if (iVar3 < 0) {
      FUN_0056bca0(&DAT_007d69d8);
      goto LAB_00562cf6;
    }
    if (((*(int *)(in_EAX + 0x1c) == *(int *)(in_EAX + 0x24)) &&
        (*(int *)(in_EAX + 0x20) == *(int *)(in_EAX + 0x28))) && (*(int *)(in_EAX + 0x2c) == 0)) {
      FUN_00597100(local_46c,&local_4a8,&local_4a4);
    }
    FUN_00597060(local_46c);
    FUN_0052d050(local_470);
    local_470 = 0;
    if ((local_4a8 < 0) || (local_4a4 < 0)) {
      if (0xb4 < local_4c0 / local_494) goto LAB_00562a0f;
      iVar5 = 0;
      iVar3 = FUN_0055bda0(&local_49c,local_4c0,0,param_4,param_1,param_6);
      if (iVar3 != -1) {
        *(undefined4 *)(iVar1 + 0x25ac) = local_498;
        puVar2 = (undefined4 *)
                 FUN_0056e030(4,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x11f8);
        *(undefined4 **)(iVar1 + 0x2500) = puVar2;
        if (puVar2 == (undefined4 *)0x0) {
          FUN_0056bca0(&DAT_007d6998);
          goto LAB_00562cf6;
        }
        *(undefined4 *)(iVar1 + 0x11f4) = local_49c;
        *(undefined4 *)(iVar1 + 0x11f8) = local_498;
        *(uint *)(iVar1 + 0x11fc) = local_494;
        *(undefined4 *)(iVar1 + 0x1200) = local_490;
        *(undefined2 *)(iVar1 + 0x1204) = local_48c;
        *(int *)(iVar1 + 0x24fc) = local_4c4;
        *(uint *)(iVar1 + 0x24f8) = local_4c0;
        *puVar2 = 1;
        local_4c4 = 0;
        if (0 < *(int *)(iVar1 + 0x70)) {
          local_4b8 = (int *)(iVar1 + 0x2504);
          iVar3 = iVar1 + 0xc4;
          do {
            if (*local_4b8 != 1) {
              iVar4 = FUN_005518a0(iVar3,0,local_4c0,&local_4b0,&local_4bc,&local_4b4,&local_4a0);
              if (iVar4 != 0) {
                FUN_0056bb10(&DAT_007d6504);
                goto LAB_00562cf6;
              }
              FUN_0056d420(local_4b0,*(undefined4 *)(iVar1 + 0x24fc),local_4bc);
              if (local_4b4 != 0) {
                FUN_0056d420(local_4b4,*(int *)(iVar1 + 0x24fc) + local_4bc,local_4a0);
              }
              iVar4 = FUN_00551980(iVar3,local_4b0,local_4bc,local_4b4,local_4a0);
              if (iVar4 != 0) {
                FUN_0056bb10(&DAT_007d64dc);
                goto LAB_00562cf6;
              }
            }
            local_4b8 = local_4b8 + 1;
            iVar5 = iVar5 + 1;
            iVar3 = iVar3 + 0x1b8;
          } while (iVar5 < *(int *)(iVar1 + 0x70));
        }
        goto LAB_00562c29;
      }
      if (local_4c4 != 0) {
        FUN_0056e1d0(local_4c4);
        goto LAB_00562a6f;
      }
    }
    else {
      *(int *)(in_EAX + 0x20) = local_4a8;
      *(int *)(in_EAX + 0x28) = local_4a4;
LAB_00562a0f:
      if (local_4c4 != 0) {
        FUN_0056e1d0(local_4c4);
LAB_00562a6f:
        local_4c4 = 0;
      }
    }
    *(undefined4 *)(in_EAX + 8) = 2;
  }
  iVar1 = FUN_00560520();
  if (iVar1 != -1) {
    FUN_00561320(param_1,param_6);
LAB_00562c29:
    if (*(int *)(in_EAX + 0x1c) != *(int *)(in_EAX + 0x24)) {
      FUN_00562830(*(int *)(in_EAX + 0x1c),*(int *)(in_EAX + 0x24),param_1,param_6);
      return 0;
    }
    if (*(int *)(in_EAX + 0x20) != *(int *)(in_EAX + 0x28)) {
      FUN_00562540(*(int *)(in_EAX + 0x20),*(int *)(in_EAX + 0x28),param_1,param_6);
    }
    return 0;
  }
LAB_00562cf6:
  if (local_4c4 != 0) {
    FUN_0056e1d0(local_4c4);
  }
  if (local_470 != 0) {
    FUN_0052d050(local_470);
  }
  if (-1 < local_4ac) {
    FUN_005525d0(local_4ac);
  }
  FUN_00597060(local_46c);
  return 0xffffffff;
}

