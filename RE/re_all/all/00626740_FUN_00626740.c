
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00626740(int param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  float *pfVar6;
  uint uVar7;
  float10 fVar8;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc [4];
  int *local_ac;
  float local_a8;
  float local_a4 [5];
  undefined1 local_90 [32];
  undefined1 local_70 [16];
  undefined1 local_60 [32];
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  piVar1 = *(int **)(param_1 + 0x170);
  switch(piVar1[8] + -1) {
  case 0:
    uVar7 = 0;
    pfVar6 = local_bc;
    do {
      iVar2 = *(int *)(param_1 + 0x170);
      local_bc[0] = 0.0;
      local_bc[1] = 0.0;
      local_bc[2] = 0.0;
      local_bc[3] = 0.0;
      *pfVar6 = 1.0;
      *(undefined4 *)(iVar2 + 0x10 + *(int *)(iVar2 + 0x20) * 4) = 0;
      iVar5 = *(int *)(param_1 + 0x168) + -1;
      *(int *)(param_1 + 0x168) = iVar5;
      *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x20) * 4) =
           *(undefined4 *)(param_1 + 0x158 + iVar5 * 4);
      uVar4 = *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x20) * 4);
      *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 1;
      FUN_00626d70(local_bc,uVar4);
      cVar3 = FUN_00626740();
      if (cVar3 != '\0') {
        return 1;
      }
      iVar2 = *(int *)(param_1 + 0x170);
      iVar5 = *(int *)(iVar2 + 0x20) + -1;
      *(int *)(iVar2 + 0x20) = iVar5;
      *(undefined4 *)(param_1 + 0x158 + *(int *)(param_1 + 0x168) * 4) =
           *(undefined4 *)(iVar2 + iVar5 * 4);
      local_c4 = -local_bc[2];
      local_c0 = -local_bc[1];
      *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + 1;
      local_c8 = -local_bc[0];
      FUN_005fc500(&local_c8,&local_c0,&local_c4);
      iVar2 = *(int *)(param_1 + 0x170);
      *(undefined4 *)(iVar2 + 0x10 + *(int *)(iVar2 + 0x20) * 4) = 0;
      iVar5 = *(int *)(param_1 + 0x168) + -1;
      *(int *)(param_1 + 0x168) = iVar5;
      *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x20) * 4) =
           *(undefined4 *)(param_1 + 0x158 + iVar5 * 4);
      uVar4 = *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x20) * 4);
      *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 1;
      FUN_00626d70(local_90,uVar4);
      cVar3 = FUN_00626740();
      if (cVar3 != '\0') {
        return 1;
      }
      iVar2 = *(int *)(param_1 + 0x170);
      pfVar6 = pfVar6 + 1;
      iVar5 = *(int *)(iVar2 + 0x20) + -1;
      *(int *)(iVar2 + 0x20) = iVar5;
      *(undefined4 *)(param_1 + 0x158 + *(int *)(param_1 + 0x168) * 4) =
           *(undefined4 *)(iVar2 + iVar5 * 4);
      uVar7 = uVar7 + 1;
      *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + 1;
    } while (uVar7 < 3);
    break;
  case 1:
    iVar2 = *piVar1;
    iVar5 = piVar1[1];
    local_c8 = *(float *)(iVar5 + 0x18) - *(float *)(iVar2 + 0x18);
    local_c0 = *(float *)(iVar5 + 0x14) - *(float *)(iVar2 + 0x14);
    local_c4 = *(float *)(iVar5 + 0x10) - *(float *)(iVar2 + 0x10);
    FUN_005fc500(&local_c4,&local_c0,&local_c8);
    uVar7 = 0;
    pfVar6 = local_a4;
    do {
      pfVar6 = pfVar6 + 1;
      local_a4[1] = 0.0;
      local_a4[2] = 0.0;
      local_a4[3] = 0.0;
      local_a4[4] = 0.0;
      *pfVar6 = 1.0;
      FUN_006170e0(local_bc,local_a4 + 1);
      fVar8 = (float10)FUN_005fcc30(local_bc);
      if ((float10)_DAT_007d5344 < fVar8) {
        iVar2 = *(int *)(param_1 + 0x170);
        *(undefined4 *)(iVar2 + 0x10 + *(int *)(iVar2 + 0x20) * 4) = 0;
        iVar5 = *(int *)(param_1 + 0x168) + -1;
        *(int *)(param_1 + 0x168) = iVar5;
        *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x20) * 4) =
             *(undefined4 *)(param_1 + 0x158 + iVar5 * 4);
        uVar4 = *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x20) * 4);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 1;
        FUN_00626d70(local_bc,uVar4);
        cVar3 = FUN_00626740();
        if (cVar3 != '\0') {
          return 1;
        }
        iVar2 = *(int *)(param_1 + 0x170);
        iVar5 = *(int *)(iVar2 + 0x20) + -1;
        *(int *)(iVar2 + 0x20) = iVar5;
        *(undefined4 *)(param_1 + 0x158 + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(iVar2 + iVar5 * 4);
        local_c8 = -local_bc[2];
        local_c0 = -local_bc[1];
        *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + 1;
        local_c4 = -local_bc[0];
        FUN_005fc500(&local_c4,&local_c0,&local_c8);
        iVar2 = *(int *)(param_1 + 0x170);
        *(undefined4 *)(iVar2 + 0x10 + *(int *)(iVar2 + 0x20) * 4) = 0;
        iVar5 = *(int *)(param_1 + 0x168) + -1;
        *(int *)(param_1 + 0x168) = iVar5;
        *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x20) * 4) =
             *(undefined4 *)(param_1 + 0x158 + iVar5 * 4);
        uVar4 = *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x20) * 4);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 1;
        FUN_00626d70(local_60,uVar4);
        cVar3 = FUN_00626740();
        if (cVar3 != '\0') {
          return 1;
        }
        iVar2 = *(int *)(param_1 + 0x170);
        iVar5 = *(int *)(iVar2 + 0x20) + -1;
        *(int *)(iVar2 + 0x20) = iVar5;
        *(undefined4 *)(param_1 + 0x158 + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(iVar2 + iVar5 * 4);
        *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + 1;
      }
      uVar7 = uVar7 + 1;
      if (2 < uVar7) {
        return 0;
      }
    } while( true );
  case 2:
    iVar2 = *piVar1;
    iVar5 = piVar1[2];
    local_c8 = *(float *)(iVar5 + 0x18) - *(float *)(iVar2 + 0x18);
    local_c0 = *(float *)(iVar5 + 0x14) - *(float *)(iVar2 + 0x14);
    local_c4 = *(float *)(iVar5 + 0x10) - *(float *)(iVar2 + 0x10);
    FUN_005fc500(&local_c4,&local_c0,&local_c8);
    iVar2 = (*(int **)(param_1 + 0x170))[1];
    iVar5 = **(int **)(param_1 + 0x170);
    local_a8 = *(float *)(iVar2 + 0x18) - *(float *)(iVar5 + 0x18);
    local_a4[0] = *(float *)(iVar2 + 0x14) - *(float *)(iVar5 + 0x14);
    local_ac = (int *)(*(float *)(iVar2 + 0x10) - *(float *)(iVar5 + 0x10));
    FUN_005fc500(&local_ac,local_a4,&local_a8);
    FUN_006170e0(local_bc,local_40);
    fVar8 = (float10)FUN_005fcc30(local_bc);
    if ((float10)_DAT_007d5344 < fVar8) {
      iVar2 = *(int *)(param_1 + 0x170);
      *(undefined4 *)(iVar2 + 0x10 + *(int *)(iVar2 + 0x20) * 4) = 0;
      iVar5 = *(int *)(param_1 + 0x168) + -1;
      *(int *)(param_1 + 0x168) = iVar5;
      *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x20) * 4) =
           *(undefined4 *)(param_1 + 0x158 + iVar5 * 4);
      uVar4 = *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x20) * 4);
      *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 1;
      FUN_00626d70(local_bc,uVar4);
      cVar3 = FUN_00626740();
      if (cVar3 != '\0') {
        return 1;
      }
      iVar2 = *(int *)(param_1 + 0x170);
      iVar5 = *(int *)(iVar2 + 0x20) + -1;
      *(int *)(iVar2 + 0x20) = iVar5;
      *(undefined4 *)(param_1 + 0x158 + *(int *)(param_1 + 0x168) * 4) =
           *(undefined4 *)(iVar2 + iVar5 * 4);
      local_ac = (int *)-local_bc[2];
      local_a4[0] = -local_bc[1];
      *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + 1;
      local_a8 = -local_bc[0];
      FUN_005fc500(&local_a8,local_a4,&local_ac);
      iVar2 = *(int *)(param_1 + 0x170);
      *(undefined4 *)(iVar2 + 0x10 + *(int *)(iVar2 + 0x20) * 4) = 0;
      iVar5 = *(int *)(param_1 + 0x168) + -1;
      *(int *)(param_1 + 0x168) = iVar5;
      *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x20) * 4) =
           *(undefined4 *)(param_1 + 0x158 + iVar5 * 4);
      uVar4 = *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x20) * 4);
      *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 1;
      FUN_00626d70(local_70,uVar4);
      cVar3 = FUN_00626740();
      if (cVar3 == '\0') {
        iVar2 = *(int *)(param_1 + 0x170);
        iVar5 = *(int *)(iVar2 + 0x20) + -1;
        *(int *)(iVar2 + 0x20) = iVar5;
        *(undefined4 *)(param_1 + 0x158 + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(iVar2 + iVar5 * 4);
        *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + 1;
        return 0;
      }
      return 1;
    }
    break;
  case 3:
    piVar1 = *(int **)(param_1 + 0x170);
    local_ac = piVar1;
    uVar4 = FUN_005fc590(local_30,piVar1[2] + 0x10,piVar1[3] + 0x10);
    uVar4 = FUN_005fc590(local_20,piVar1[1] + 0x10,piVar1[3] + 0x10,uVar4);
    uVar4 = FUN_005fc590(local_10,*piVar1 + 0x10,piVar1[3] + 0x10,uVar4);
    fVar8 = (float10)FUN_006252d0(uVar4);
    if ((float10)_DAT_007d5344 < ABS(fVar8)) {
      return 1;
    }
  }
  return 0;
}

