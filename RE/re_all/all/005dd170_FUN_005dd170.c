
undefined4 FUN_005dd170(int param_1,int param_2)

{
  undefined8 uVar1;
  undefined2 local_18 [4];
  undefined8 local_10;
  
  FUN_0056d380(local_18,0,0x18);
  local_18[0] = 0x14;
  uVar1 = __allmul(param_2,param_2 >> 0x1f,&DAT_00989680,0);
  local_10 = __aulldiv(uVar1,*(undefined4 *)(param_1 + 0x3c),0);
  (**(code **)(**(int **)(param_1 + 0x4a) + 0x20))(*(int **)(param_1 + 0x4a),&DAT_00ddb33c,local_18)
  ;
  *(undefined4 *)(param_1 + 0x6a) = 0;
  *(undefined4 *)(param_1 + 0x6e) = 0;
  *(undefined4 *)(param_1 + 0x454) = 0;
  *(undefined4 *)(param_1 + 0x458) = 0;
  *(uint *)(param_1 + 0x45c) = (uint)*(ushort *)(param_1 + 0x44) * param_2;
  return 0;
}

