
int FUN_006c2da0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  longlong lVar7;
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  uint local_4;
  
  iVar1 = param_1;
  if (*(int *)(param_1 + 0x5c) < 2) {
    return -0x83;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    return -0x8a;
  }
  if ((param_3 < 1) && (param_3 < 0)) {
    return -0x83;
  }
  lVar7 = FUN_006c3080(param_1,param_2,param_3,&param_1);
  if (lVar7 == -1) {
    return -0x83;
  }
  iVar5 = param_1 * 0x160 + *(int *)(iVar1 + 0x1c);
  local_14 = *(undefined4 *)(iVar5 + 0x24);
  local_18 = *(undefined4 *)(iVar5 + 0x20);
  FUN_006c0c50(&param_2,lVar7,local_18,local_14);
  if ((param_1 == *(int *)(iVar1 + 0x60)) && (3 < *(int *)(iVar1 + 0x5c))) {
    local_10 = *(uint *)(iVar1 + 0x68);
    local_c = *(uint *)(iVar1 + 0x6c);
    if ((local_10 & local_c) != 0xffffffff) {
      uVar2 = *(int *)(iVar1 + 0x2200) - *(int *)(iVar1 + 0x21fc);
      FUN_006bff30(&local_10,local_10,local_c,-(uVar2 & ((int)uVar2 < 1) - 1));
      iVar3 = FUN_006c0c50(&local_20,local_10,local_c,local_18,local_14);
      if (iVar3 == 0) {
        iVar3 = (param_3 - local_1c) - (uint)(param_2 < local_20);
        if (((-1 < iVar3) && (iVar3 < 1)) && ((iVar3 < 0 || (param_2 - local_20 < 0x10e0)))) {
          *(uint *)(iVar1 + 100) = param_2 - local_20;
          return 0;
        }
      }
    }
  }
  iVar3 = FUN_006c3170(iVar1,lVar7,param_1);
  if (iVar3 < 0) {
    return iVar3;
  }
  if ((0 < param_3) || ((-1 < param_3 && (*(uint *)(iVar5 + 0x34) < param_2)))) {
    local_28 = param_2 - 0xf00;
    local_24 = param_3 - (uint)(param_2 < 0xf00);
    if ((-1 < local_24) &&
       ((local_24 != 0 && (int)(uint)(param_2 < 0xf00) <= param_3 || (local_28 != 0))))
    goto LAB_006c2f65;
  }
  local_28 = 0;
  local_24 = 0;
LAB_006c2f65:
  do {
    iVar5 = *(int *)(iVar1 + 0x21d4);
    iVar3 = *(int *)(iVar1 + 0x21d0);
    local_10 = *(uint *)(iVar1 + 0x68);
    local_c = *(uint *)(iVar1 + 0x6c);
    if (iVar3 < iVar5) {
      puVar6 = (uint *)((iVar3 + 0x10) * 0x20 + iVar1);
      do {
        local_4 = puVar6[1];
        uVar2 = *puVar6;
        iVar4 = FUN_006c0c50(&local_20,uVar2,local_4,local_18,local_14);
        if ((iVar4 == 0) &&
           ((local_24 < local_1c || ((local_24 <= local_1c && (local_28 < local_20)))))) break;
        iVar3 = iVar3 + 1;
        local_c = local_4;
        puVar6 = puVar6 + 8;
        local_10 = uVar2;
      } while (iVar3 < iVar5);
    }
    *(uint *)(iVar1 + 0x68) = local_10;
    *(uint *)(iVar1 + 0x6c) = local_c;
    *(int *)(iVar1 + 0x21d0) = iVar3;
    if (iVar3 < iVar5) {
      FUN_006c0c50(&local_20,local_10,local_c,local_18,local_14);
      if (local_24 <= local_1c) {
        if (local_24 < local_1c) {
          return -0x89;
        }
        if (local_28 < local_20) {
          return -0x89;
        }
      }
      *(uint *)(iVar1 + 100) = param_2 - local_20;
      return 0;
    }
    iVar5 = FUN_006c26f0(iVar1,0,0xffffffff,0xffffffff,1,0,1);
    if (iVar5 < 1) {
      return -0x89;
    }
  } while( true );
}

