
undefined4
FUN_00527a30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined4 local_4;
  
  uVar1 = param_3;
  iVar4 = param_1;
  iVar2 = FUN_0057ba50(param_1 + 0xa0,param_3,param_4,param_5,&param_1,&local_4,param_7,0,param_9);
  if (iVar2 < 0) {
    FUN_0056bc50(L"Image File Load Error : %s \n",uVar1);
    return 0xffffffff;
  }
  iVar3 = FUN_0057b5a0(iVar2);
  uVar1 = param_2;
  iVar5 = DAT_00a37e70;
  if (DAT_00a37e70 == 0) {
    iVar5 = 0x10;
  }
  *(int *)(iVar4 + 0xb0) = iVar5;
  if (((*(int *)(iVar3 + 0xc0) == 0) || (*(int *)(iVar3 + 0x34) != 0)) ||
     (*(int *)(*(int *)(iVar3 + 0x634) + 0x178) != 1)) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  *(int *)(iVar4 + 0xc4) = iVar5;
  *(undefined4 *)(iVar4 + 0xb8) = 0;
  *(undefined4 *)(iVar4 + 0xbc) = 0;
  *(undefined4 *)(iVar4 + 0x108) = 1;
  *(undefined4 *)(iVar4 + 0xc0) = 0;
  *(undefined4 *)(iVar4 + 200) = 0;
  *(undefined4 *)(iVar4 + 0xd0) = 0;
  *(undefined4 *)(iVar4 + 0x100) = 0;
  *(undefined4 *)(iVar4 + 0xd4) = 1;
  *(undefined4 *)(iVar4 + 0xd8) = 0;
  if (((*(int *)(iVar3 + 0x34) != 0) && (DAT_00a37dd4 != 0)) ||
     (((*(int *)(iVar3 + 0xbc) == 0 && (DAT_00a37dc8 != 0)) &&
      ((*(int *)(iVar3 + 0xc0) == 0 ||
       ((*(int *)(iVar3 + 0x634) != 0 && (*(int *)(*(int *)(iVar3 + 0x634) + 0x178) != 1)))))))) {
    *(undefined4 *)(iVar4 + 0xfc) = 0;
    *(undefined4 *)(iVar4 + 0xf8) = 0;
    *(undefined4 *)(iVar4 + 0xf4) = 0;
    *(undefined4 *)(iVar4 + 0xf0) = 0;
    *(undefined4 *)(iVar4 + 0xec) = 0;
    *(undefined4 *)(iVar4 + 0xe8) = 0;
    *(undefined4 *)(iVar4 + 0xe4) = 0;
    *(undefined4 *)(iVar4 + 0xe0) = 0;
    *(undefined4 *)(iVar4 + 0xdc) = 1;
  }
  bVar6 = *(int *)(iVar3 + 0xbc) == 0;
  if (bVar6) {
    iVar3 = param_1;
  }
  else {
    iVar3 = param_1 / 2;
  }
  iVar4 = FUN_00522dc0(iVar4 + 0xac,param_2,iVar3,local_4,param_6,!bVar6 || iVar5 != 0,0,0,0,
                       0xffffffff,param_9);
  if (iVar4 == -1) {
    FUN_0056bc50(L"Graph Handle Setup Error : %s",param_3);
    return 0xffffffff;
  }
  iVar4 = FUN_00519300(uVar1,param_9);
  if (iVar4 != 0) {
    *(int *)(iVar4 + 0x34) = iVar2;
    FUN_0057b940(iVar2,FUN_00523780,uVar1);
  }
  return 0;
}

