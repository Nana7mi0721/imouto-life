
undefined4
FUN_0052fdc0(undefined4 param_1,uint param_2,int param_3,int param_4,int param_5,uint param_6,
            int param_7,undefined1 param_8,undefined4 param_9)

{
  undefined2 *puVar1;
  uint in_EAX;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 local_4;
  
  iVar3 = 0;
  local_4 = 0;
  if ((int)in_EAX < 0) {
    in_EAX = -(uint)(DAT_00a4b76c != 0) & 2;
  }
  if (param_4 < 0) {
    param_4 = 0x10;
  }
  if (param_5 < 0) {
    param_5 = 6;
  }
  if (param_7 < 0) {
    param_7 = 1;
  }
  if (param_6 < 8) {
    if (param_6 != 0) {
      uVar4 = (undefined2)*(undefined4 *)(&DAT_0084cb84 + param_6 * 4);
      goto LAB_0052fe36;
    }
  }
  else {
    local_4 = 1;
    param_6 = FUN_0056cec0();
  }
  uVar4 = 0xffff;
LAB_0052fe36:
  if ((in_EAX & 1) == 0) {
    param_7 = 0;
  }
  if (DAT_00a4b76c != 0) {
    in_EAX = ((in_EAX & 1) != 0) + 2;
  }
  if ((((DAT_00cc5c60 != 0) && (-1 < (int)param_2)) && ((param_2 & 0x7c000000) == DAT_00cc5c88)) &&
     ((int)(param_2 & 0xffff) < DAT_00cc5c90)) {
    iVar3 = *(int *)(DAT_00cc5c64 + (param_2 & 0xffff) * 4);
  }
  iVar2 = FUN_005167e0();
  if ((iVar2 == 8) && ((in_EAX & 2) != 0)) {
    in_EAX = in_EAX & 0xfffffffd;
  }
  *(undefined2 *)(iVar3 + 0x93162) = (undefined2)param_4;
  *(undefined2 *)(iVar3 + 0x9316c) = (undefined2)param_6;
  *(undefined2 *)(iVar3 + 0x93160) = (undefined2)param_5;
  *(undefined2 *)(iVar3 + 0x9316e) = uVar4;
  *(undefined1 *)(iVar3 + 0x93168) = param_8;
  *(uint *)(iVar3 + 0x93184) = in_EAX;
  *(int *)(iVar3 + 0x93188) = param_7;
  *(undefined4 *)(iVar3 + 0x93178) = 0;
  *(undefined4 *)(iVar3 + 0x9317c) = 0;
  *(undefined4 *)(iVar3 + 0x93180) = 0;
  *(undefined4 *)(iVar3 + 0x93174) = 0xffffffff;
  *(undefined4 *)(iVar3 + 0x34) = 0;
  *(undefined4 *)(iVar3 + 0x38) = 0;
  puVar1 = (undefined2 *)(iVar3 + 0x92f60);
  if (param_3 == 0) {
    *puVar1 = 0;
  }
  else {
    FUN_0056cf70(puVar1,0x200,param_3);
  }
  iVar2 = FUN_00595780(param_1,iVar3,local_4);
  if (iVar2 == 0) {
    if (DAT_00aba24c == 0) {
      FUN_0057a980();
    }
    iVar2 = DAT_00aba24c;
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    FUN_005764b0(puVar1,0xffffffff,DAT_00aba250,iVar3 + 0x92e60,0x100,iVar2);
    iVar2 = FUN_0052f260(param_1,iVar3,param_9);
    if (-1 < iVar2) {
      return 0;
    }
    FUN_00595f60(iVar3);
  }
  return 0xffffffff;
}

