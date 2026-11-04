
int FUN_0054e820(int param_1,undefined4 *param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_43c;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined4 local_42c;
  undefined1 local_428 [1064];
  
  iVar4 = 0;
  if ((*(char *)(param_1 + 5) == '\b') && (param_5 == 0)) {
    FUN_0056d380(param_2,0,0x2c);
    *param_2 = 0x28;
    param_2[1] = *(undefined4 *)(param_1 + 0x428);
    param_2[2] = -*(int *)(param_1 + 0x42c);
    *(undefined2 *)(param_2 + 3) = 1;
    *(undefined2 *)((int)param_2 + 0xe) = 8;
    param_2[4] = 0;
    FUN_0056d420(param_2 + 10,param_1 + 0x28,0x400);
    iVar1 = *(int *)(param_1 + 0x428) + 3;
    iVar1 = ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) * 4;
    if ((param_4 != 1) && (iVar1 == *(int *)(param_1 + 0x430))) {
      *param_3 = *(int *)(param_1 + 0x434);
      return param_4;
    }
    local_43c = FUN_0056e030(*(int *)(param_1 + 0x42c) * iVar1,
                             "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xa0b);
    *param_3 = local_43c;
    if (local_43c == 0) {
      return -1;
    }
    iVar3 = *(int *)(param_1 + 0x434);
    if (0 < *(int *)(param_1 + 0x42c)) {
      do {
        FUN_0056d420(local_43c,iVar3,*(undefined4 *)(param_1 + 0x428));
        iVar3 = iVar3 + *(int *)(param_1 + 0x430);
        local_43c = local_43c + iVar1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0x42c));
    }
  }
  else {
    FUN_0056d380(param_2,0,0x2c);
    *param_2 = 0x28;
    param_2[1] = *(undefined4 *)(param_1 + 0x428);
    param_2[2] = -*(int *)(param_1 + 0x42c);
    *(undefined2 *)(param_2 + 3) = 1;
    *(undefined2 *)((int)param_2 + 0xe) = 0x18;
    iVar4 = (*(int *)(param_1 + 0x428) + 1) * 3;
    iVar4 = ((int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2) * 4;
    if (((*(char *)(param_1 + 5) == '\x18') &&
        (((param_4 != 1 && (*(int *)(param_1 + 0x10) == 0xff0000)) &&
         (*(int *)(param_1 + 0x14) == 0xff00)))) && (*(int *)(param_1 + 0x18) == 0xff)) {
      if (iVar4 == *(int *)(param_1 + 0x430)) {
        *param_3 = *(int *)(param_1 + 0x434);
        return param_4;
      }
      iVar1 = FUN_0056e030(*(int *)(param_1 + 0x42c) * iVar4,
                           "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xa56);
      *param_3 = iVar1;
      if (iVar1 == 0) {
        return -1;
      }
      local_43c = *(int *)(param_1 + 0x434);
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x42c)) {
        iVar2 = *(int *)(param_1 + 0x430);
        do {
          FUN_0056d420(iVar1,local_43c,iVar2);
          iVar2 = *(int *)(param_1 + 0x430);
          local_43c = local_43c + iVar2;
          iVar3 = iVar3 + 1;
          iVar1 = iVar1 + iVar4;
        } while (iVar3 < *(int *)(param_1 + 0x42c));
        return 1;
      }
    }
    else {
      iVar1 = FUN_0056e030(*(int *)(param_1 + 0x42c) * iVar4,
                           "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0xa3a);
      *param_3 = iVar1;
      if (iVar1 == 0) {
        return -1;
      }
      FUN_00544560(local_428);
      local_430 = *(undefined4 *)(param_1 + 0x428);
      local_42c = *(undefined4 *)(param_1 + 0x42c);
      local_434 = 0;
      local_438 = 0;
      FUN_00549b20(iVar1,iVar4,local_428,*(undefined4 *)(param_1 + 0x434),
                   *(undefined4 *)(param_1 + 0x430),param_1,0,0,0,0,0,&local_438,0,0,0,0,0,0,0,0);
    }
  }
  return 1;
}

