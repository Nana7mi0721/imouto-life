
int * __thiscall FUN_00615380(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = param_3;
  if (*(int *)(param_3 + 0xc) < *(int *)(param_2 + 0xc)) {
    param_3 = param_2;
    param_2 = iVar1;
  }
  uVar7 = *(int *)(param_3 + 0xc) << 0x10 | *(uint *)(param_2 + 0xc);
  uVar5 = uVar7 + ~(uVar7 << 0xf);
  uVar5 = ((int)uVar5 >> 10 ^ uVar5) * 9;
  uVar5 = uVar5 ^ (int)uVar5 >> 6;
  uVar5 = uVar5 + ~(uVar5 << 0xb);
  iVar1 = *(int *)(param_1 + 0xc);
  uVar5 = ((int)uVar5 >> 0x10 ^ uVar5) & iVar1 - 1U;
  iVar2 = *(int *)(*(int *)(param_1 + 0x2c) + uVar5 * 4);
  do {
    if (iVar2 == -1) {
LAB_00615434:
      iVar2 = *(int *)(param_1 + 8);
      iVar3 = *(int *)(param_1 + 8);
      local_10 = 0;
      local_c = 0;
      local_8 = 0;
      local_4 = 0;
      if (iVar3 == *(int *)(param_1 + 0xc)) {
        if (iVar3 == 0) {
          iVar4 = 1;
        }
        else {
          iVar4 = iVar3 * 2;
        }
        FUN_0060d190(iVar4);
      }
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      if (*(int *)(param_1 + 0x10) + iVar3 * 0x10 != 0) {
        FUN_00616110(&local_10);
      }
      piVar6 = (int *)(*(int *)(param_1 + 0x10) + iVar3 * 0x10);
      if (*(int **)(param_1 + 0x48) != (int *)0x0) {
        (**(code **)(**(int **)(param_1 + 0x48) + 4))(param_2,param_3);
      }
      if (iVar1 < *(int *)(param_1 + 0xc)) {
        FUN_00615260();
        uVar7 = uVar7 + ~(uVar7 << 0xf);
        uVar5 = ((int)uVar7 >> 10 ^ uVar7) * 9;
        uVar5 = uVar5 ^ (int)uVar5 >> 6;
        uVar5 = uVar5 + ~(uVar5 << 0xb);
        uVar5 = ((int)uVar5 >> 0x10 ^ uVar5) & *(int *)(param_1 + 0xc) - 1U;
      }
      if (piVar6 == (int *)0x0) {
        piVar6 = (int *)0x0;
      }
      else if (*(int *)(param_2 + 0xc) < *(int *)(param_3 + 0xc)) {
        *piVar6 = param_2;
        piVar6[1] = param_3;
        piVar6[2] = 0;
        piVar6[3] = 0;
      }
      else {
        *piVar6 = param_3;
        piVar6[1] = param_2;
        piVar6[2] = 0;
        piVar6[3] = 0;
      }
      piVar6[2] = 0;
      piVar6[3] = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x40) + iVar2 * 4) =
           *(undefined4 *)(*(int *)(param_1 + 0x2c) + uVar5 * 4);
      *(int *)(*(int *)(param_1 + 0x2c) + uVar5 * 4) = iVar2;
      return piVar6;
    }
    piVar6 = (int *)(iVar2 * 0x10 + *(int *)(param_1 + 0x10));
    if ((*(uint *)(*piVar6 + 0xc) == *(uint *)(param_2 + 0xc)) &&
       (*(int *)(piVar6[1] + 0xc) == *(int *)(param_3 + 0xc))) {
      if ((iVar2 != -1) &&
         (piVar6 = (int *)(iVar2 * 0x10 + *(int *)(param_1 + 0x10)), piVar6 != (int *)0x0)) {
        return piVar6;
      }
      goto LAB_00615434;
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0x40) + iVar2 * 4);
  } while( true );
}

