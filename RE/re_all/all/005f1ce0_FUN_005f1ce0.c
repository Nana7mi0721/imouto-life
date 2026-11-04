
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005f1ce0(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,int param_6)

{
  uint uVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  undefined1 *puVar5;
  int *piVar6;
  undefined *puVar7;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined1 local_e4 [32];
  undefined4 local_c4;
  undefined1 local_c0 [64];
  undefined1 local_80 [128];
  
  bVar3 = false;
  iVar4 = FUN_00567b30();
  if (iVar4 == 0) {
    return 0xffffffff;
  }
  FUN_005160a0(0);
  if ((((param_2 < 4) && (param_3 < 4)) && (param_4 < 4)) && (param_5 < 4)) {
LAB_005f1db9:
    param_6 = param_6 + (param_5 + (param_4 + (param_3 + param_2 * 4) * 4) * 4) * 2;
    piVar6 = (int *)(&DAT_00dda654 + param_6 * 4);
    if ((-1 < *(int *)(&DAT_00dda654 + param_6 * 4)) || (DAT_00e8c77c == 0)) goto LAB_005f20fa;
    iVar4 = FUN_00522070((&DAT_00e8c780)[param_6],(int)(short)(&DAT_00e8cf80)[param_6]);
    *piVar6 = iVar4;
    if (iVar4 < 0) {
      FUN_0056bca0(&DAT_00802d68);
      return 0xffffffff;
    }
  }
  else {
    uVar1 = param_2 - 4;
    if (((uVar1 < 4) && (param_3 - 4 < 4)) && ((param_4 - 4 < 4 && (param_5 - 4 < 4)))) {
      uVar2 = *(undefined4 *)(param_1 + 0xc);
      bVar3 = true;
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(param_1 + 8) = uVar2;
      param_2 = uVar1;
      param_3 = param_3 - 4;
      param_4 = param_4 - 4;
      param_5 = param_5 - 4;
      goto LAB_005f1db9;
    }
    if (((param_2 == param_3) && (param_2 == param_4)) && ((param_2 != 7 && (param_2 != 3)))) {
      bVar3 = uVar1 < 4;
      if (bVar3) {
        uVar2 = *(undefined4 *)(param_1 + 0xc);
        param_3 = param_3 - 4;
        param_4 = param_4 - 4;
        param_5 = param_5 + 4;
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 8);
        *(undefined4 *)(param_1 + 8) = uVar2;
        param_2 = uVar1;
      }
      iVar4 = param_6 + (param_5 + param_2 * 4) * 2;
      piVar6 = (int *)(&DAT_00dda5b4 + iVar4 * 4);
      if (-1 < *(int *)(&DAT_00dda5b4 + iVar4 * 4)) goto LAB_005f20fa;
      puVar5 = &DAT_00802d60;
      if (param_6 == 0) {
        puVar5 = &DAT_007d0621;
      }
      FUN_0056d240(local_c0,0x40,"RGBAMix_S%sS%sS%sB%s%s.pso",(&PTR_DAT_00a057a0)[param_2],
                   (&PTR_DAT_00a057a0)[param_3],(&PTR_DAT_00a057a0)[param_4],
                   (&PTR_s_BasBF_Add_AlphaCh_PMA_pso_00a05790)[param_5],puVar5);
      iVar4 = FUN_005ee300(0);
      *piVar6 = iVar4;
      if (iVar4 < 0) {
        FUN_005764b0(local_c0,0xffffffff,0x7ffd,local_80,0x80,0x4b0);
        FUN_0056bca0(&DAT_00802d00,local_80);
        return 0xffffffff;
      }
    }
    else {
      if (param_2 == 0) {
        if ((param_3 == 1) && (param_4 == 2)) {
LAB_005f2045:
          iVar4 = param_6 + param_5 * 2;
          piVar6 = (int *)(&DAT_00dda594 + iVar4 * 4);
          if (-1 < *(int *)(&DAT_00dda594 + iVar4 * 4)) goto LAB_005f20fa;
          puVar5 = &DAT_00802d60;
          if (param_6 == 0) {
            puVar5 = &DAT_007d0621;
          }
          FUN_0056d240(local_c0,0x40,"RGBAMix_S%sS%sS%sB%s%s.pso",PTR_DAT_00a057a0,PTR_DAT_00a057a4,
                       (&PTR_DAT_00a057a0)[param_4],
                       (&PTR_s_BasBF_Add_AlphaCh_PMA_pso_00a05790)[param_5],puVar5);
          iVar4 = FUN_005ee300(0);
          *piVar6 = iVar4;
          if (iVar4 < 0) {
            FUN_005764b0(local_c0,0xffffffff,0x7ffd,local_80,0x80,0x4b0);
            puVar7 = &DAT_00802d00;
            goto LAB_005f1fd7;
          }
          goto LAB_005f20f0;
        }
      }
      else if (((param_2 == 4) && (param_3 == 5)) && (param_4 == 6)) {
        param_3 = 1;
        bVar3 = true;
        uVar2 = *(undefined4 *)(param_1 + 0xc);
        param_5 = param_5 + 4;
        param_2 = 0;
        param_4 = 2;
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 8);
        *(undefined4 *)(param_1 + 8) = uVar2;
        goto LAB_005f2045;
      }
      piVar6 = (int *)(&DAT_00dda5ac + param_6 * 4);
      if (-1 < *(int *)(&DAT_00dda5ac + param_6 * 4)) goto LAB_005f20fa;
      iVar4 = FUN_005ee300(0);
      *piVar6 = iVar4;
      if (iVar4 < 0) {
        FUN_005764b0((&PTR_s_RGBAMix_Base_pso_00a05798)[param_6],0xffffffff,0x7ffd,local_80,0x80,
                     0x4b0);
        puVar7 = &DAT_00802650;
LAB_005f1fd7:
        FUN_0056bca0(puVar7,local_80);
        return 0xffffffff;
      }
    }
  }
LAB_005f20f0:
  FUN_00580830(iVar4,piVar6);
LAB_005f20fa:
  local_ec = DAT_00a38dd8;
  local_e8 = DAT_00a38ddc;
  FUN_0059c240(&DAT_00ddb600,3);
  FUN_0056d420(local_e4,&DAT_00a38d78,8);
  local_10c = *(undefined4 *)(param_1 + 0x18);
  local_108 = *(undefined4 *)(param_1 + 0x18);
  local_104 = *(undefined4 *)(param_1 + 0x18);
  local_100 = *(undefined4 *)(param_1 + 0x18);
  local_f0 = (float)_DAT_00804a60;
  local_c4 = 2;
  local_fc = (float)(int)param_2 + local_f0;
  local_f8 = (float)(int)param_3 + local_f0;
  local_f4 = (float)(int)param_4 + local_f0;
  local_f0 = local_f0 + (float)(int)param_5;
  FUN_0059cb80(&DAT_00ddb600,3,1,0,&local_10c,2,0);
  FUN_00516d40(*piVar6);
  FUN_005ee5d0(1,0);
  FUN_005ee580();
  if (bVar3) {
    uVar2 = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(param_1 + 8) = uVar2;
  }
  FUN_0059cc80(&DAT_00ddb600,3,1,0,2);
  return 0;
}

