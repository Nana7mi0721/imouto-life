
void FUN_0079ce50(int *param_1,undefined2 *param_2,short *param_3,short *param_4)

{
  int *piVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = (int)param_4;
  piVar1 = param_1;
  if (0 < (int)param_4) {
    param_1 = (int *)param_2;
    param_4 = param_3;
    param_2 = (undefined2 *)iVar4;
    do {
      iVar7 = *param_4 * 0x400;
      uVar3 = iVar7 - *piVar1;
      iVar4 = ((int)((uVar3 & 0xffff) * (int)DAT_008379f8) >> 0x10) +
              ((int)uVar3 >> 0x10) * (int)DAT_008379f8;
      iVar8 = *piVar1 + iVar4;
      *piVar1 = iVar4 + iVar7;
      uVar3 = iVar8 - piVar1[1];
      iVar4 = ((int)((uVar3 & 0xffff) * (int)DAT_008379fa) >> 0x10) +
              ((int)uVar3 >> 0x10) * (int)DAT_008379fa;
      iVar6 = piVar1[1] + iVar4;
      uVar3 = iVar6 - piVar1[2];
      piVar1[1] = iVar8 + iVar4;
      iVar4 = ((int)uVar3 >> 0x10) * (int)DAT_008379fc +
              uVar3 + ((int)((uVar3 & 0xffff) * (int)DAT_008379fc) >> 0x10);
      uVar3 = (piVar1[2] + iVar4 >> 9) + 1;
      piVar1[2] = iVar6 + iVar4;
      uVar5 = uVar3 & 0xfffffffe;
      if ((int)uVar5 < 0xffff) {
        if ((int)uVar5 < -0x10000) {
          uVar2 = 0x8000;
        }
        else {
          uVar2 = (undefined2)((int)uVar3 >> 1);
        }
      }
      else {
        uVar2 = 0x7fff;
      }
      *(undefined2 *)param_1 = uVar2;
      uVar3 = iVar7 - piVar1[3];
      iVar4 = ((int)((uVar3 & 0xffff) * (int)DAT_00837a00) >> 0x10) +
              ((int)uVar3 >> 0x10) * (int)DAT_00837a00;
      iVar6 = piVar1[3] + iVar4;
      uVar3 = iVar6 - piVar1[4];
      piVar1[3] = iVar4 + iVar7;
      iVar4 = ((int)((uVar3 & 0xffff) * (int)DAT_00837a02) >> 0x10) +
              ((int)uVar3 >> 0x10) * (int)DAT_00837a02;
      iVar7 = piVar1[4] + iVar4;
      piVar1[4] = iVar6 + iVar4;
      iVar4 = piVar1[5];
      uVar3 = iVar7 - iVar4;
      iVar6 = ((int)uVar3 >> 0x10) * (int)DAT_00837a04 +
              uVar3 + ((int)((uVar3 & 0xffff) * (int)DAT_00837a04) >> 0x10);
      piVar1[5] = iVar7 + iVar6;
      uVar3 = (iVar4 + iVar6 >> 9) + 1;
      uVar5 = uVar3 & 0xfffffffe;
      if ((int)uVar5 < 0xffff) {
        if ((int)uVar5 < -0x10000) {
          uVar2 = 0x8000;
        }
        else {
          uVar2 = (undefined2)((int)uVar3 >> 1);
        }
      }
      else {
        uVar2 = 0x7fff;
      }
      param_4 = param_4 + 1;
      *(undefined2 *)((int)param_1 + 2) = uVar2;
      param_1 = (int *)((int)param_1 + 4);
      param_2 = (undefined2 *)((int)param_2 + -1);
    } while (param_2 != (undefined2 *)0x0);
  }
  return;
}

