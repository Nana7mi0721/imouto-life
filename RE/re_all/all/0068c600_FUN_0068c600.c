
void FUN_0068c600(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iStack_c;
  
  puVar3 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0xa0);
  param_1[0x6e] = (int)puVar3;
  *puVar3 = &LAB_0068c7a0;
  puVar3[1] = &LAB_0068c7c0;
  *(undefined1 *)(puVar3 + 2) = 0;
  if ((char)param_1[0x44] != '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x1a;
    (**(code **)*param_1)(param_1);
  }
  iStack_c = 0;
  if (0 < param_1[9]) {
    piVar8 = (int *)(param_1[0x31] + 8);
    puVar7 = puVar3 + 0xd;
    do {
      iVar4 = (piVar8[7] * *piVar8) / param_1[0x48];
      iVar5 = (piVar8[8] * piVar8[1]) / param_1[0x49];
      iVar1 = param_1[0x47];
      iVar2 = param_1[0x46];
      puVar7[0xc] = iVar5;
      if ((char)piVar8[0xb] == '\0') {
        *puVar7 = &LAB_0068c8d0;
      }
      else if ((iVar4 == iVar2) && (iVar5 == iVar1)) {
        *puVar7 = &LAB_0068c8c0;
      }
      else {
        if (iVar4 * 2 == iVar2) {
          if (iVar5 == iVar1) {
            *puVar7 = &LAB_0068ca00;
          }
          else {
            if ((iVar4 * 2 != iVar2) || (iVar5 * 2 != iVar1)) goto LAB_0068c6fd;
            *puVar7 = &LAB_0068ca60;
          }
        }
        else {
LAB_0068c6fd:
          if ((iVar2 % iVar4 == 0) && (iVar1 % iVar5 == 0)) {
            *puVar7 = &LAB_0068c8e0;
            *(char *)((int)puVar3 + iStack_c + 0x8c) = (char)(iVar2 / iVar4);
            *(char *)((int)puVar3 + iStack_c + 0x96) = (char)(iVar1 / iVar5);
          }
          else {
            *(undefined4 *)(*param_1 + 0x14) = 0x27;
            (**(code **)*param_1)(param_1);
          }
        }
        iVar1 = param_1[1];
        uVar6 = FUN_006848c0(param_1[0x17],param_1[0x46],param_1[0x47]);
        uVar6 = (**(code **)(iVar1 + 8))(param_1,1,uVar6);
        puVar7[-10] = uVar6;
      }
      iStack_c = iStack_c + 1;
      puVar7 = puVar7 + 1;
      piVar8 = piVar8 + 0x16;
    } while (iStack_c < param_1[9]);
  }
  return;
}

