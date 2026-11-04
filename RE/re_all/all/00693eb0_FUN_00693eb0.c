
void FUN_00693eb0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piStack_4;
  
  piVar6 = param_1;
  bVar5 = true;
  puVar7 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x70);
  param_1[100] = (int)puVar7;
  *puVar7 = FUN_0065f670;
  puVar7[1] = &LAB_00694080;
  *(undefined1 *)(puVar7 + 2) = 0;
  if (*(char *)((int)param_1 + 0xd3) != '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x1a;
    (**(code **)*param_1)(param_1);
  }
  piVar1 = param_1 + 0x13;
  piVar2 = param_1 + 0x15;
  param_1 = (int *)0x0;
  if (0 < *piVar1) {
    piStack_4 = (int *)(*piVar2 + 8);
    puVar10 = puVar7 + 3;
    do {
      iVar3 = piVar6[0x40];
      iVar8 = (piStack_4[7] * *piStack_4) / piVar6[0x42];
      iVar4 = piVar6[0x41];
      iVar9 = (piStack_4[8] * piStack_4[1]) / piVar6[0x43];
      puVar10[10] = iVar9;
      if ((iVar3 == iVar8) && (iVar4 == iVar9)) {
        if (piVar6[0x36] == 0) {
          *puVar10 = FUN_006942c0;
        }
        else {
          *puVar10 = &LAB_006947b0;
          *(undefined1 *)(puVar7 + 2) = 1;
        }
      }
      else if (iVar3 == iVar8 * 2) {
        if (iVar4 == iVar9) {
          bVar5 = false;
          *puVar10 = FUN_00694310;
        }
        else {
          if ((iVar3 != iVar8 * 2) || (iVar4 != iVar9 * 2)) goto LAB_00693fd3;
          if (piVar6[0x36] == 0) {
            *puVar10 = &LAB_006943c0;
          }
          else {
            *puVar10 = &LAB_006944b0;
            *(undefined1 *)(puVar7 + 2) = 1;
          }
        }
      }
      else {
LAB_00693fd3:
        if ((iVar3 % iVar8 == 0) && (iVar4 % iVar9 == 0)) {
          bVar5 = false;
          *puVar10 = &LAB_00694110;
          *(char *)((int)param_1 + 0x5c + (int)puVar7) = (char)(iVar3 / iVar8);
          *(char *)((int)param_1 + 0x66 + (int)puVar7) = (char)(iVar4 / iVar9);
        }
        else {
          *(undefined4 *)(*piVar6 + 0x14) = 0x27;
          (**(code **)*piVar6)(piVar6);
        }
      }
      param_1 = (int *)((int)param_1 + 1);
      puVar10 = puVar10 + 1;
      piStack_4 = piStack_4 + 0x16;
    } while ((int)param_1 < piVar6[0x13]);
  }
  if ((piVar6[0x36] != 0) && (!bVar5)) {
    *(undefined4 *)(*piVar6 + 0x14) = 0x65;
    (**(code **)(*piVar6 + 4))(piVar6,0);
  }
  return;
}

