
void __fastcall FUN_00791690(int *param_1)

{
  float fVar1;
  undefined4 *puVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  float local_30 [12];
  
  pfVar3 = (float *)(param_1 + 4);
  iVar4 = 0;
  do {
    iVar5 = *param_1;
    local_30[0] = 0.0;
    local_30[1] = 0.0;
    local_30[2] = 0.0;
    local_30[3] = 0.0;
    *(undefined4 *)((int)local_30 + iVar4) = 0x3f800000;
    (**(code **)(iVar5 + 0x30))(local_30 + 4,local_30);
    fVar1 = (float)param_1[3];
    *(undefined4 *)((int)local_30 + iVar4 + -8) = 0xbf800000;
    pfVar3[4] = *(float *)((int)local_30 + iVar4 + 8) + fVar1;
    puVar2 = (undefined4 *)(**(code **)(*param_1 + 0x30))(local_30 + 6,local_30 + -2);
    iVar5 = iVar4 + 4;
    local_30[4] = (float)*puVar2;
    local_30[5] = (float)puVar2[1];
    local_30[6] = (float)puVar2[2];
    local_30[7] = (float)puVar2[3];
    *pfVar3 = *(float *)((int)local_30 + iVar4 + 0x10) - (float)param_1[3];
    pfVar3 = pfVar3 + 1;
    iVar4 = iVar5;
  } while (iVar5 < 0xc);
  return;
}

