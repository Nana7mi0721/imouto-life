
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005f4850(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,int param_6)

{
  uint uVar1;
  undefined4 uVar2;
  float *pfVar3;
  bool bVar4;
  float fVar5;
  int iVar6;
  undefined1 *puVar7;
  int *piVar8;
  undefined *puVar9;
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  bVar4 = false;
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if ((((param_2 < 4) && (param_3 < 4)) && (param_4 < 4)) && (param_5 < 4)) {
LAB_005f491f:
    param_6 = param_6 + (param_5 + (param_4 + (param_3 + param_2 * 4) * 4) * 4) * 2;
    piVar8 = (int *)(&DAT_00dda654 + param_6 * 4);
    if ((-1 < *(int *)(&DAT_00dda654 + param_6 * 4)) || (DAT_00f23514 == 0)) goto LAB_005f4c34;
    iVar6 = FUN_00522070((&DAT_00f23518)[param_6 * 2],(&DAT_00f2351c)[param_6 * 2]);
    *piVar8 = iVar6;
    if (iVar6 < 0) {
      FUN_0056bca0(&DAT_00802d68);
      return 0xffffffff;
    }
  }
  else {
    uVar1 = param_2 - 4;
    if (((uVar1 < 4) && (param_3 - 4 < 4)) && ((param_4 - 4 < 4 && (param_5 - 4 < 4)))) {
      uVar2 = *(undefined4 *)(param_1 + 0xc);
      bVar4 = true;
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(param_1 + 8) = uVar2;
      param_2 = uVar1;
      param_3 = param_3 - 4;
      param_4 = param_4 - 4;
      param_5 = param_5 - 4;
      goto LAB_005f491f;
    }
    if (((param_2 == param_3) && (param_2 == param_4)) && ((param_2 != 7 && (param_2 != 3)))) {
      bVar4 = uVar1 < 4;
      if (bVar4) {
        uVar2 = *(undefined4 *)(param_1 + 0xc);
        param_3 = param_3 - 4;
        param_4 = param_4 - 4;
        param_5 = param_5 + 4;
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 8);
        *(undefined4 *)(param_1 + 8) = uVar2;
        param_2 = uVar1;
      }
      iVar6 = param_6 + (param_5 + param_2 * 4) * 2;
      piVar8 = (int *)(&DAT_00dda5b4 + iVar6 * 4);
      if (-1 < *(int *)(&DAT_00dda5b4 + iVar6 * 4)) goto LAB_005f4c34;
      puVar7 = &DAT_00802d60;
      if (param_6 == 0) {
        puVar7 = &DAT_007d0621;
      }
      FUN_0056d240(local_80,0x40,"RGBAMix_S%sS%sS%sB%s%s.pso",(&PTR_DAT_00a058e8)[param_2],
                   (&PTR_DAT_00a058e8)[param_3],(&PTR_DAT_00a058e8)[param_4],
                   (&PTR_s_BasBF_Add_AlphaCh_PMA_pso_00a058d8)[param_5],puVar7);
      iVar6 = FUN_005f2360(0);
      *piVar8 = iVar6;
      if (iVar6 < 0) {
        FUN_005764b0(local_80,0xffffffff,0x7ffd,local_40,0x40,0x4b0);
        FUN_0056bca0(&DAT_00802d00,local_40);
        return 0xffffffff;
      }
    }
    else {
      if (param_2 == 0) {
        if ((param_3 == 1) && (param_4 == 2)) {
LAB_005f4b8e:
          iVar6 = param_6 + param_5 * 2;
          piVar8 = (int *)(&DAT_00dda594 + iVar6 * 4);
          if (-1 < *(int *)(&DAT_00dda594 + iVar6 * 4)) goto LAB_005f4c34;
          puVar7 = &DAT_00802d60;
          if (param_6 == 0) {
            puVar7 = &DAT_007d0621;
          }
          FUN_0056d240(local_80,0x40,"RGBAMix_S%sS%sS%sB%s%s.pso",PTR_DAT_00a058e8,PTR_DAT_00a058ec,
                       (&PTR_DAT_00a058e8)[param_4],
                       (&PTR_s_BasBF_Add_AlphaCh_PMA_pso_00a058d8)[param_5],puVar7);
          iVar6 = FUN_005f2360(0);
          *piVar8 = iVar6;
          if (iVar6 < 0) {
            FUN_005764b0(local_80,0xffffffff,0x7ffd,local_40,0x40,0x4b0);
            puVar9 = &DAT_00802d00;
            goto LAB_005f4b24;
          }
          goto LAB_005f4c2a;
        }
      }
      else if (((param_2 == 4) && (param_3 == 5)) && (param_4 == 6)) {
        param_3 = 1;
        bVar4 = true;
        uVar2 = *(undefined4 *)(param_1 + 0xc);
        param_5 = param_5 + 4;
        param_2 = 0;
        param_4 = 2;
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 8);
        *(undefined4 *)(param_1 + 8) = uVar2;
        goto LAB_005f4b8e;
      }
      piVar8 = (int *)(&DAT_00dda5ac + param_6 * 4);
      if (-1 < *(int *)(&DAT_00dda5ac + param_6 * 4)) goto LAB_005f4c34;
      iVar6 = FUN_005f2360(0);
      *piVar8 = iVar6;
      if (iVar6 < 0) {
        FUN_005764b0((&PTR_s_RGBAMix_Base_pso_00a058e0)[param_6],0xffffffff,0x7ffd,local_40,0x40,
                     0x4b0);
        puVar9 = &DAT_00802650;
LAB_005f4b24:
        FUN_0056bca0(puVar9,local_40);
        return 0xffffffff;
      }
    }
  }
LAB_005f4c2a:
  FUN_00580830(iVar6,piVar8);
LAB_005f4c34:
  pfVar3 = *(float **)(DAT_00ef1ba8 + 8);
  fVar5 = (float)_DAT_00804a60;
  *pfVar3 = (float)(int)param_2 + fVar5;
  pfVar3[1] = (float)(int)param_3 + fVar5;
  pfVar3[2] = (float)(int)param_4 + fVar5;
  pfVar3[3] = fVar5 + (float)(int)param_5;
  *(undefined4 *)(DAT_00ef1ba8 + 0xc) = 1;
  FUN_005bc8e0(DAT_00ef1ba8);
  FUN_005f23c0(*piVar8,0,1,0xffffffff,0);
  if (bVar4) {
    uVar2 = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(param_1 + 8) = uVar2;
  }
  return 0;
}

