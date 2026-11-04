
undefined4
FUN_0067cae0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,char *param_7,
            int param_8)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 1;
  if (((param_7 == (char *)0x0) || (*param_7 != s_1_2_8_00821ac0[0])) || (param_8 != 0x38)) {
    return 0xfffffffa;
  }
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 0;
    if (*(int *)(param_1 + 0x20) == 0) {
      *(code **)(param_1 + 0x20) = FUN_0067eb00;
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      *(code **)(param_1 + 0x24) = FUN_0067eb20;
    }
    if (param_2 == -1) {
      param_2 = 6;
    }
    if (param_4 < 0) {
      iVar4 = 0;
      param_4 = -param_4;
    }
    else if (0xf < param_4) {
      iVar4 = 2;
      param_4 = param_4 + -0x10;
    }
    if (((((0 < param_5) && (param_5 < 10)) &&
         ((param_3 == 8 && ((7 < param_4 && (param_4 < 0x10)))))) && (-1 < param_2)) &&
       (((param_2 < 10 && (-1 < param_6)) && (param_6 < 5)))) {
      if (param_4 == 8) {
        param_4 = 9;
      }
      piVar2 = (int *)(**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x16c4);
      if (piVar2 == (int *)0x0) {
        return 0xfffffffc;
      }
      *(int **)(param_1 + 0x1c) = piVar2;
      piVar2[6] = iVar4;
      piVar2[0xc] = param_4;
      iVar5 = 1 << ((byte)param_4 & 0x1f);
      iVar4 = 1 << ((byte)(param_5 + 7) & 0x1f);
      piVar2[0x14] = param_5 + 7;
      *piVar2 = param_1;
      piVar2[7] = 0;
      piVar2[0xb] = iVar5;
      piVar2[0x13] = iVar4;
      piVar2[0x15] = iVar4 + -1;
      piVar2[0xd] = iVar5 + -1;
      piVar2[0x16] = (param_5 + 9U) / 3;
      iVar4 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),iVar5,2);
      piVar2[0xe] = iVar4;
      iVar4 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),piVar2[0xb],2);
      piVar2[0x10] = iVar4;
      iVar4 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),piVar2[0x13],2);
      piVar2[0x11] = iVar4;
      piVar2[0x5b0] = 0;
      iVar4 = 1 << ((char)param_5 + 6U & 0x1f);
      piVar2[0x5a7] = iVar4;
      iVar4 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),iVar4,4);
      uVar1 = piVar2[0x5a7];
      piVar2[2] = iVar4;
      piVar2[3] = uVar1 * 4;
      if (((piVar2[0xe] == 0) || (piVar2[0x10] == 0)) || ((piVar2[0x11] == 0 || (iVar4 == 0)))) {
        piVar2[1] = 0x29a;
        *(undefined **)(param_1 + 0x18) = PTR_s_insufficient_memory_00821ae0;
        FUN_0067d7a0(param_1);
        return 0xfffffffc;
      }
      *(undefined1 *)(piVar2 + 9) = 8;
      piVar2[0x5a9] = iVar4 + (uVar1 & 0xfffffffe);
      piVar2[0x5a6] = iVar4 + uVar1 * 3;
      piVar2[0x22] = param_6;
      piVar2[0x21] = param_2;
      uVar3 = FUN_0067cdb0(param_1);
      return uVar3;
    }
  }
  return 0xfffffffe;
}

