
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00566c60(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_c;
  int local_4;
  
  if ((((((int)param_3 < 0) || ((param_3 & 0x7c000000) != 0x24000000)) ||
       (uVar7 = param_3 & 0xffff, 0xff < uVar7)) ||
      ((iVar8 = uVar7 * 0x5c, (&DAT_00aa84b8)[uVar7 * 0x17] == 0 ||
       ((&DAT_00aa84bc)[uVar7 * 0x17] * 0x10000 != (param_3 & 0x3ff0000))))) ||
     (*(int *)(&DAT_00aa84c0 + iVar8) != 0)) {
    return 0xffffffff;
  }
  local_24 = FUN_00516960();
  FUN_00516940(0);
  local_38 = DAT_00aa84b4;
  if (DAT_00aa84b4 == -1) {
    local_38 = FUN_00530d70();
  }
  iVar3 = FUN_00536eb0(local_38);
  local_28 = iVar3;
  if (DAT_00aa84a0 == 1) {
    iVar4 = FUN_00550060(0);
    if (DAT_00aa84a8 < iVar4 - _DAT_00aa84a4) {
      DAT_00aa84ac = (uint)(DAT_00aa84ac != 1);
      _DAT_00aa84a4 = FUN_00550060(0);
    }
  }
  else {
    DAT_00aa84ac = 1;
  }
  FUN_005162d0(&local_20);
  if (*(int *)(&DAT_00aa8500 + iVar8) == 0) {
    local_c = local_1c;
    local_4 = local_14;
    iVar4 = local_18;
    iVar6 = local_20;
  }
  else {
    local_4 = *(int *)(&DAT_00aa8510 + iVar8);
    local_c = *(int *)(&DAT_00aa8508 + iVar8);
    iVar4 = *(int *)(&DAT_00aa850c + iVar8);
    iVar6 = *(int *)(&DAT_00aa8504 + iVar8);
    FUN_005217e0(iVar6,*(undefined4 *)(&DAT_00aa8508 + iVar8),iVar4,local_4);
  }
  iVar2 = local_38;
  iVar3 = (iVar3 / 10) * 3 + iVar3;
  if ((iVar6 == iVar4) || (local_4 == local_c)) {
    if (*(int *)(&DAT_00aa8500 + iVar8) != 0) {
      FUN_005217e0(local_20,local_1c,local_18,local_14);
    }
    return 0xffffffff;
  }
  iVar5 = param_1;
  if (param_1 < iVar6) {
    iVar5 = iVar6;
  }
  iVar1 = param_2;
  if (param_2 < local_c) {
    iVar1 = local_c;
  }
  for (; iVar4 < iVar5; iVar5 = iVar5 + (iVar6 - iVar4)) {
    iVar1 = iVar1 + iVar3;
  }
  local_34 = (local_4 - iVar1) / iVar3;
  if (local_34 == 0) {
    local_34 = 1;
  }
  FUN_00563c40(param_1,param_2,iVar3,*(undefined4 *)(&DAT_00aa84e0 + iVar8),0xffffffff,0,0,local_38,
               0,0,0,0,0,0,&local_30,&local_38);
  local_2c = local_4 - iVar3;
  if (local_38 < local_2c) {
    *(undefined4 *)(&DAT_00aa84d8 + iVar8) = 0;
  }
  else {
    iVar4 = *(int *)(&DAT_00aa84d8 + iVar8);
    iVar6 = *(int *)(&DAT_00aa84dc + iVar8);
    if (iVar6 < iVar4) {
      *(int *)(&DAT_00aa84d8 + iVar8) = iVar6;
    }
    else {
      FUN_00563c40(param_1,param_2,iVar3,*(int *)(&DAT_00aa84e0 + iVar8) + iVar4 * 2,iVar6 - iVar4,0
                   ,0,iVar2,0,0,0,0,0,0,&local_30,&local_38);
      if (*(int *)(&DAT_00aa84d8 + iVar8) < *(int *)(&DAT_00aa84dc + iVar8)) {
        do {
          if (local_34 == 1) {
            if (local_38 == param_2) break;
          }
          else if (local_38 <= local_2c) break;
          iVar4 = *(int *)(&DAT_00aa84d8 + iVar8);
          if ((*(ushort *)(*(int *)(&DAT_00aa84e0 + iVar8) + iVar4 * 2) & 0xfc00) == 0xd800) {
            iVar4 = iVar4 + 2;
          }
          else {
            iVar4 = iVar4 + 1;
          }
          *(int *)(&DAT_00aa84d8 + iVar8) = iVar4;
          FUN_00563c40(param_1,param_2,iVar3,*(int *)(&DAT_00aa84e0 + iVar8) + iVar4 * 2,
                       *(int *)(&DAT_00aa84dc + iVar8) - iVar4,0,0,iVar2,0,0,0,0,0,0,&local_30,
                       &local_38);
        } while (*(int *)(&DAT_00aa84d8 + iVar8) < *(int *)(&DAT_00aa84dc + iVar8));
      }
    }
  }
  FUN_00563c40(param_1,param_2,iVar3,
               *(int *)(&DAT_00aa84e0 + iVar8) + *(int *)(&DAT_00aa84d8 + iVar8) * 2,
               *(int *)(&DAT_00aa84dc + iVar8) - *(int *)(&DAT_00aa84d8 + iVar8),0,0,iVar2,0,0,0,0,0
               ,0,&local_34,&local_30);
  if ((DAT_00aa84ac == 1) && (param_3 == DAT_00aa84b0)) {
    FUN_00563eb0(local_34,local_30,local_34 + 2,local_30 + local_28,iVar3,DAT_00aa843c,1);
  }
  iVar4 = *(int *)(&DAT_00aa84d8 + iVar8);
  FUN_00563c40(param_1,param_2,iVar3,*(int *)(&DAT_00aa84e0 + iVar8) + iVar4 * 2,0xffffffff,
               DAT_00aa8434,DAT_00aa8438,iVar2,DAT_00aa8448,DAT_00aa8440,DAT_00aa8444,
               *(int *)(&DAT_00aa84d0 + iVar8) - iVar4,*(int *)(&DAT_00aa84d4 + iVar8) - iVar4,1,0,0
              );
  if (*(int *)(&DAT_00aa8500 + iVar8) != 0) {
    FUN_005217e0(local_20,local_1c,local_18,local_14);
  }
  if (param_3 == DAT_00aa84b0) {
    FUN_00565140(local_34,local_30,5,param_4);
  }
  FUN_00516940(local_24);
  return 0;
}

