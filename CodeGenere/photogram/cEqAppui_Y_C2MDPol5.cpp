// File Automatically generated by eLiSe

#include "general/all.h"
#include "private/all.h"
#include "cEqAppui_Y_C2MDPol5.h"


cEqAppui_Y_C2MDPol5::cEqAppui_Y_C2MDPol5():
    cElCompiledFonc(1)
{
   AddIntRef (cIncIntervale("Intr",0,42));
   AddIntRef (cIncIntervale("Orient",42,48));
   Close(false);
}



void cEqAppui_Y_C2MDPol5::ComputeVal()
{
   double tmp0_ = mCompCoord[42];
   double tmp1_ = mCompCoord[44];
   double tmp2_ = cos(tmp0_);
   double tmp3_ = cos(tmp1_);
   double tmp4_ = sin(tmp0_);
   double tmp5_ = mCompCoord[43];
   double tmp6_ = sin(tmp5_);
   double tmp7_ = -(tmp6_);
   double tmp8_ = sin(tmp1_);
   double tmp9_ = -(tmp4_);
   double tmp10_ = tmp2_*tmp7_;
   double tmp11_ = mCompCoord[45];
   double tmp12_ = mLocXTer-tmp11_;
   double tmp13_ = -(tmp8_);
   double tmp14_ = tmp4_*tmp7_;
   double tmp15_ = mCompCoord[46];
   double tmp16_ = mLocYTer-tmp15_;
   double tmp17_ = cos(tmp5_);
   double tmp18_ = mCompCoord[47];
   double tmp19_ = mLocZTer-tmp18_;
   double tmp20_ = ElSquare(mLocYIm);
   double tmp21_ = ElSquare(mLocXIm);
   double tmp22_ = VCube(mLocYIm);
   double tmp23_ = VCube(mLocXIm);
   double tmp24_ = VPow4(mLocYIm);
   double tmp25_ = VPow4(mLocXIm);

  mVal[0] = ((tmp9_*tmp3_+tmp10_*tmp8_)*(tmp12_)+(tmp2_*tmp3_+tmp14_*tmp8_)*(tmp16_)+tmp17_*tmp8_*(tmp19_))/((tmp9_*tmp13_+tmp10_*tmp3_)*(tmp12_)+(tmp2_*tmp13_+tmp14_*tmp3_)*(tmp16_)+tmp17_*tmp3_*(tmp19_))-(mCompCoord[21]+mCompCoord[22]*mLocYIm+mCompCoord[23]*mLocXIm+mCompCoord[24]*tmp20_+mCompCoord[25]*mLocXIm*mLocYIm+mCompCoord[26]*tmp21_+mCompCoord[27]*tmp22_+mCompCoord[28]*mLocXIm*tmp20_+mCompCoord[29]*tmp21_*mLocYIm+mCompCoord[30]*tmp23_+mCompCoord[31]*tmp24_+mCompCoord[32]*mLocXIm*tmp22_+mCompCoord[33]*tmp21_*tmp20_+mCompCoord[34]*tmp23_*mLocYIm+mCompCoord[35]*tmp25_+mCompCoord[36]*VPow5(mLocYIm)+mCompCoord[37]*mLocXIm*tmp24_+mCompCoord[38]*tmp21_*tmp22_+mCompCoord[39]*tmp23_*tmp20_+mCompCoord[40]*tmp25_*mLocYIm+mCompCoord[41]*VPow5(mLocXIm));

}


void cEqAppui_Y_C2MDPol5::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[42];
   double tmp1_ = mCompCoord[44];
   double tmp2_ = cos(tmp0_);
   double tmp3_ = cos(tmp1_);
   double tmp4_ = sin(tmp0_);
   double tmp5_ = mCompCoord[43];
   double tmp6_ = sin(tmp5_);
   double tmp7_ = -(tmp6_);
   double tmp8_ = sin(tmp1_);
   double tmp9_ = -(tmp4_);
   double tmp10_ = tmp2_*tmp7_;
   double tmp11_ = mCompCoord[45];
   double tmp12_ = mLocXTer-tmp11_;
   double tmp13_ = -(tmp8_);
   double tmp14_ = tmp4_*tmp7_;
   double tmp15_ = mCompCoord[46];
   double tmp16_ = mLocYTer-tmp15_;
   double tmp17_ = cos(tmp5_);
   double tmp18_ = mCompCoord[47];
   double tmp19_ = mLocZTer-tmp18_;
   double tmp20_ = ElSquare(mLocYIm);
   double tmp21_ = ElSquare(mLocXIm);
   double tmp22_ = VCube(mLocYIm);
   double tmp23_ = VCube(mLocXIm);
   double tmp24_ = VPow4(mLocYIm);
   double tmp25_ = VPow4(mLocXIm);
   double tmp26_ = VPow5(mLocYIm);
   double tmp27_ = VPow5(mLocXIm);
   double tmp28_ = -(1);
   double tmp29_ = tmp28_*tmp4_;
   double tmp30_ = tmp10_*tmp8_;
   double tmp31_ = tmp9_*tmp13_;
   double tmp32_ = tmp10_*tmp3_;
   double tmp33_ = tmp31_+tmp32_;
   double tmp34_ = (tmp33_)*(tmp12_);
   double tmp35_ = tmp2_*tmp13_;
   double tmp36_ = tmp14_*tmp3_;
   double tmp37_ = tmp35_+tmp36_;
   double tmp38_ = (tmp37_)*(tmp16_);
   double tmp39_ = tmp34_+tmp38_;
   double tmp40_ = tmp17_*tmp3_;
   double tmp41_ = tmp40_*(tmp19_);
   double tmp42_ = tmp39_+tmp41_;
   double tmp43_ = tmp9_*tmp3_;
   double tmp44_ = tmp43_+tmp30_;
   double tmp45_ = (tmp44_)*(tmp12_);
   double tmp46_ = tmp2_*tmp3_;
   double tmp47_ = tmp14_*tmp8_;
   double tmp48_ = tmp46_+tmp47_;
   double tmp49_ = (tmp48_)*(tmp16_);
   double tmp50_ = tmp45_+tmp49_;
   double tmp51_ = tmp17_*tmp8_;
   double tmp52_ = tmp51_*(tmp19_);
   double tmp53_ = tmp50_+tmp52_;
   double tmp54_ = -(tmp2_);
   double tmp55_ = tmp29_*tmp7_;
   double tmp56_ = -(tmp17_);
   double tmp57_ = tmp56_*tmp2_;
   double tmp58_ = tmp56_*tmp4_;
   double tmp59_ = tmp28_*tmp6_;
   double tmp60_ = ElSquare(tmp42_);
   double tmp61_ = tmp28_*tmp8_;
   double tmp62_ = -(tmp3_);

  mVal[0] = (tmp53_)/(tmp42_)-(mCompCoord[21]+mCompCoord[22]*mLocYIm+mCompCoord[23]*mLocXIm+mCompCoord[24]*tmp20_+mCompCoord[25]*mLocXIm*mLocYIm+mCompCoord[26]*tmp21_+mCompCoord[27]*tmp22_+mCompCoord[28]*mLocXIm*tmp20_+mCompCoord[29]*tmp21_*mLocYIm+mCompCoord[30]*tmp23_+mCompCoord[31]*tmp24_+mCompCoord[32]*mLocXIm*tmp22_+mCompCoord[33]*tmp21_*tmp20_+mCompCoord[34]*tmp23_*mLocYIm+mCompCoord[35]*tmp25_+mCompCoord[36]*tmp26_+mCompCoord[37]*mLocXIm*tmp24_+mCompCoord[38]*tmp21_*tmp22_+mCompCoord[39]*tmp23_*tmp20_+mCompCoord[40]*tmp25_*mLocYIm+mCompCoord[41]*tmp27_);

  mCompDer[0][0] = 0;
  mCompDer[0][1] = 0;
  mCompDer[0][2] = 0;
  mCompDer[0][3] = 0;
  mCompDer[0][4] = 0;
  mCompDer[0][5] = 0;
  mCompDer[0][6] = 0;
  mCompDer[0][7] = 0;
  mCompDer[0][8] = 0;
  mCompDer[0][9] = 0;
  mCompDer[0][10] = 0;
  mCompDer[0][11] = 0;
  mCompDer[0][12] = 0;
  mCompDer[0][13] = 0;
  mCompDer[0][14] = 0;
  mCompDer[0][15] = 0;
  mCompDer[0][16] = 0;
  mCompDer[0][17] = 0;
  mCompDer[0][18] = 0;
  mCompDer[0][19] = 0;
  mCompDer[0][20] = 0;
  mCompDer[0][21] = tmp28_;
  mCompDer[0][22] = -(mLocYIm);
  mCompDer[0][23] = -(mLocXIm);
  mCompDer[0][24] = -(tmp20_);
  mCompDer[0][25] = -(mLocXIm*mLocYIm);
  mCompDer[0][26] = -(tmp21_);
  mCompDer[0][27] = -(tmp22_);
  mCompDer[0][28] = -(mLocXIm*tmp20_);
  mCompDer[0][29] = -(tmp21_*mLocYIm);
  mCompDer[0][30] = -(tmp23_);
  mCompDer[0][31] = -(tmp24_);
  mCompDer[0][32] = -(mLocXIm*tmp22_);
  mCompDer[0][33] = -(tmp21_*tmp20_);
  mCompDer[0][34] = -(tmp23_*mLocYIm);
  mCompDer[0][35] = -(tmp25_);
  mCompDer[0][36] = -(tmp26_);
  mCompDer[0][37] = -(mLocXIm*tmp24_);
  mCompDer[0][38] = -(tmp21_*tmp22_);
  mCompDer[0][39] = -(tmp23_*tmp20_);
  mCompDer[0][40] = -(tmp25_*mLocYIm);
  mCompDer[0][41] = -(tmp27_);
  mCompDer[0][42] = (((tmp54_*tmp3_+tmp55_*tmp8_)*(tmp12_)+(tmp29_*tmp3_+tmp30_)*(tmp16_))*(tmp42_)-(tmp53_)*((tmp54_*tmp13_+tmp55_*tmp3_)*(tmp12_)+(tmp29_*tmp13_+tmp32_)*(tmp16_)))/tmp60_;
  mCompDer[0][43] = ((tmp57_*tmp8_*(tmp12_)+tmp58_*tmp8_*(tmp16_)+tmp59_*tmp8_*(tmp19_))*(tmp42_)-(tmp53_)*(tmp57_*tmp3_*(tmp12_)+tmp58_*tmp3_*(tmp16_)+tmp59_*tmp3_*(tmp19_)))/tmp60_;
  mCompDer[0][44] = (((tmp61_*tmp9_+tmp3_*tmp10_)*(tmp12_)+(tmp61_*tmp2_+tmp3_*tmp14_)*(tmp16_)+tmp3_*tmp17_*(tmp19_))*(tmp42_)-(tmp53_)*((tmp62_*tmp9_+tmp61_*tmp10_)*(tmp12_)+(tmp62_*tmp2_+tmp61_*tmp14_)*(tmp16_)+tmp61_*tmp17_*(tmp19_)))/tmp60_;
  mCompDer[0][45] = (tmp28_*(tmp44_)*(tmp42_)-(tmp53_)*tmp28_*(tmp33_))/tmp60_;
  mCompDer[0][46] = (tmp28_*(tmp48_)*(tmp42_)-(tmp53_)*tmp28_*(tmp37_))/tmp60_;
  mCompDer[0][47] = (tmp28_*tmp51_*(tmp42_)-(tmp53_)*tmp28_*tmp40_)/tmp60_;
}


void cEqAppui_Y_C2MDPol5::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqAppui_Y_C2MDPol5 Has no Der Sec");
}

void cEqAppui_Y_C2MDPol5::SetXIm(double aVal){ mLocXIm = aVal;}
void cEqAppui_Y_C2MDPol5::SetXTer(double aVal){ mLocXTer = aVal;}
void cEqAppui_Y_C2MDPol5::SetYIm(double aVal){ mLocYIm = aVal;}
void cEqAppui_Y_C2MDPol5::SetYTer(double aVal){ mLocYTer = aVal;}
void cEqAppui_Y_C2MDPol5::SetZTer(double aVal){ mLocZTer = aVal;}



double * cEqAppui_Y_C2MDPol5::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "XIm") return & mLocXIm;
   if (aName == "XTer") return & mLocXTer;
   if (aName == "YIm") return & mLocYIm;
   if (aName == "YTer") return & mLocYTer;
   if (aName == "ZTer") return & mLocZTer;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqAppui_Y_C2MDPol5::mTheAuto("cEqAppui_Y_C2MDPol5",cEqAppui_Y_C2MDPol5::Alloc);


cElCompiledFonc *  cEqAppui_Y_C2MDPol5::Alloc()
{  return new cEqAppui_Y_C2MDPol5();
}


