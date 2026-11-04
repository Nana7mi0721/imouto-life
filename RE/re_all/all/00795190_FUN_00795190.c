
void __thiscall FUN_00795190(int param_1,int *param_2,float *param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  float *pfVar5;
  int local_8;
  
  iVar4 = 0;
  pfVar5 = *(float **)(param_1 + 0x60);
  local_8 = 0;
  if (0 < *(int *)(param_1 + 0x38)) {
    do {
      local_8 = local_8 + 1;
      bVar3 = true;
      if ((pfVar5[4] < *param_3) || (*param_4 < *pfVar5)) {
        bVar3 = false;
      }
      if ((pfVar5[6] < param_3[2]) || (param_4[2] < pfVar5[2])) {
        bVar3 = false;
      }
      if ((pfVar5[5] < param_3[1]) || (param_4[1] < pfVar5[1])) {
        bVar3 = false;
      }
      fVar2 = pfVar5[8];
      if (fVar2 == -NAN) {
        if (bVar3) {
          (**(code **)(*param_2 + 4))(pfVar5[9],pfVar5[10]);
          goto LAB_0079524f;
        }
LAB_00795253:
        if (fVar2 == -NAN) goto LAB_00795265;
        pfVar1 = pfVar5 + 8;
        pfVar5 = pfVar5 + (int)*pfVar1 * 0x10;
        iVar4 = iVar4 + (int)*pfVar1;
      }
      else {
LAB_0079524f:
        if (!bVar3) goto LAB_00795253;
LAB_00795265:
        pfVar5 = pfVar5 + 0x10;
        iVar4 = iVar4 + 1;
      }
    } while (iVar4 < *(int *)(param_1 + 0x38));
  }
  if (DAT_00f488d8 < local_8) {
    DAT_00f488d8 = local_8;
  }
  return;
}

