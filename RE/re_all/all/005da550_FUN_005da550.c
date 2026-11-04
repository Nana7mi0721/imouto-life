
undefined4 FUN_005da550(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined2 local_18 [4];
  undefined8 local_10;
  
  if (*(int *)(param_1 + 0x56c) != 0) {
    FUN_0056d380(local_18,0,0x18);
    local_18[0] = 0x14;
    uVar2 = __allmul(*(undefined4 *)(param_1 + 0x584),0,param_2,param_2 >> 0x1f);
    uVar2 = __allmul(uVar2,&DAT_00989680,0);
    local_10 = __aulldiv(uVar2,*(undefined4 *)(param_1 + 0x580),0);
    (**(code **)(**(int **)(param_1 + 0x56c) + 0x20))
              (*(int **)(param_1 + 0x56c),&DAT_00ddb33c,local_18);
    *(int *)(param_1 + 0x5c0) = param_2;
    uVar2 = __allmul(*(undefined4 *)(param_1 + 0x584),0,param_2,param_2 >> 0x1f);
    uVar2 = __allmul(uVar2,1000000,0);
    uVar2 = __alldiv(uVar2,*(undefined4 *)(param_1 + 0x580),0);
    uVar3 = *(undefined4 *)(param_1 + 0x5e0);
    *(undefined8 *)(param_1 + 0x5d0) = uVar2;
    *(undefined4 *)(param_1 + 0x590) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x594) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x598) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x618) = 0;
    *(undefined4 *)(param_1 + 0x620) = 0;
    uVar1 = __alldiv(*(undefined4 *)(param_1 + 0x5d0),*(undefined4 *)(param_1 + 0x5d4),1000,0);
    FUN_0055d2a0(uVar1,uVar3);
    return 0;
  }
  if (*(int *)(param_1 + 0x62c) == 0) {
    return 0xffffffff;
  }
  local_20 = FUN_0056d580((double)*(longlong *)(param_1 + 0x638) * (double)param_2);
  local_28 = 0;
  local_24 = 0;
  (**(code **)(**(int **)(param_1 + 0x62c) + 0x38))
            (*(int **)(param_1 + 0x62c),&local_20,1,&local_28,0);
  return 0;
}

