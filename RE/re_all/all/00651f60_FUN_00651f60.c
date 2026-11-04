
int FUN_00651f60(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined8 uVar6;
  
  iVar2 = FUN_0065f680(param_1);
  if (iVar2 == 0) {
    return -1;
  }
  if ((*(uint *)(param_1 + 0xc) & 0x800) == 0) {
    puVar3 = (undefined4 *)(param_2 * 8 + *(int *)(param_1 + 0xac));
    uVar6 = (**(code **)(param_1 + 0x280))(*(undefined4 *)(param_1 + 0x274),*puVar3,puVar3[1],0);
    piVar5 = (int *)(param_2 * 8 + *(int *)(param_1 + 0xac));
    if (((int)uVar6 != *piVar5) || ((int)((ulonglong)uVar6 >> 0x20) != piVar5[1])) {
      FUN_006512e0(*(undefined4 *)(param_1 + 0x274),param_5,
                   s_Seek_error_at_row__lu__col__lu__t_00a06ed0,*(undefined4 *)(param_1 + 0x1bc),
                   *(undefined4 *)(param_1 + 0x1e8),param_2);
      return -1;
    }
    iVar2 = (**(code **)(param_1 + 0x278))(*(undefined4 *)(param_1 + 0x274),param_3,param_4);
    if (iVar2 == param_4) {
      return param_4;
    }
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),param_5,
                 s_Read_error_at_row__lu__col__lu__g_00a06e90,*(undefined4 *)(param_1 + 0x1bc),
                 *(undefined4 *)(param_1 + 0x1e8),iVar2,iVar2 >> 0x1f,param_4,param_4 >> 0x1f);
    return -1;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0xac) + param_2 * 8);
  iVar2 = iVar1 + param_4;
  if ((iVar1 >> 0x1f == *(int *)(*(int *)(param_1 + 0xac) + param_2 * 8 + 4)) &&
     (iVar4 = *(int *)(param_1 + 0x268), iVar1 <= iVar4)) {
    if (((iVar1 <= iVar2) && (param_4 <= iVar2)) && (iVar2 <= iVar4)) goto LAB_006520d8;
    iVar4 = iVar4 - iVar1;
  }
  else {
    iVar4 = 0;
  }
  if (iVar4 != param_4) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),param_5,
                 s_Read_error_at_row__lu__col__lu__t_00a06e44,*(undefined4 *)(param_1 + 0x1bc),
                 *(undefined4 *)(param_1 + 0x1e8),param_2,iVar4,iVar4 >> 0x1f,param_4,
                 param_4 >> 0x1f);
    return -1;
  }
LAB_006520d8:
  FUN_00650840(param_3,*(int *)(param_1 + 0x264) + iVar1,param_4);
  return param_4;
}

